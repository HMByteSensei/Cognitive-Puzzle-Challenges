class Solution {
    public int openLock(String[] deadends, String target) {
        HashSet<String> visited = new HashSet<>();
        Queue<String> red = new LinkedList<>();
        
        for(var d : deadends) {
            visited.add(d);
        }
        
        if(visited.contains("0000")) {
            return -1;
        }
        
        visited.add("0000");
        red.offer("0000");
        int steps = 0;
        
        while(!red.isEmpty()) {
            int len = red.size();
            for(int i=0; i<len; i++) {
                
                StringBuilder current = new StringBuilder(red.poll());
                if((current.toString()).equals(target)) {
                    return steps;
                }
                for(int j=0; j<4; j++) {
                    int inc = current.charAt(j) - '0';
                    int dec = current.charAt(j) - '0';

                    
                    inc = (inc + 1) % 10;
                    dec = (dec - 1 + 10) % 10;
                    StringBuilder comboInc = new StringBuilder(current);
                    StringBuilder comboDec = new StringBuilder(current);
                    
                    comboInc.setCharAt(j, (char) (inc + '0'));
                    comboDec.setCharAt(j, (char) (dec + '0'));
                    
                    if(!visited.contains(comboInc.toString())) {
                        visited.add(comboInc.toString());
                        red.offer(comboInc.toString());
                    }
                    if(!visited.contains(comboDec.toString())) {
                        visited.add(comboDec.toString());
                        red.offer(comboDec.toString());
                    }
                }
                
            }
            steps++;
        }
            
        
        return -1;
    }
}
