class Solution {
    public List<List<Integer>> getSkyline(int[][] buildings) {
        int[][] parovi = new int[buildings.length * 2][2];
        for(int i=0; i<buildings.length; i++) {
            int poc = buildings[i][0];
            int kraj = buildings[i][1];
            int heigh = buildings[i][2];
            
            parovi[i * 2] = new int[]{poc, -heigh};
            parovi[i * 2 + 1] = new int[]{kraj, heigh};
        }
        Arrays.sort(parovi, Comparator.comparingInt((int[] a) -> a[0])
                              .thenComparingInt(a -> a[1]));
        
        List<List<Integer>> rez = new ArrayList<>(); 
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        
        // for(var x : parovi) {
        //     for (var y : x) {
        //         System.out.print(y + "    ");
        //     }
        //     System.out.println();
        // }
        
        pq.add(0);        
        int maxHeight = 0;
        for(int i=0; i<parovi.length; i++) {
            int point = parovi[i][0];
            int height = parovi[i][1];
            
            if(height < 0) {
                pq.add(height);
            } else {
                pq.remove(-height);
            }
            
            int pqTop = -pq.peek();
            if(maxHeight != pqTop) {
                maxHeight = pqTop;
                rez.add(new ArrayList<>(Arrays.asList(point, maxHeight)));
            }
        }
        return rez;
    }
}
