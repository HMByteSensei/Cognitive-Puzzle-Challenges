class Solution {
    public int fourSumCount(int[] nums1, int[] nums2, int[] nums3, int[] nums4) {
        HashMap<Integer, Integer> mapa = new HashMap<Integer, Integer>();
        
        for(var i : nums1) {
            for(var j : nums2) {
                mapa.put(i+j, mapa.getOrDefault(i+j, 0) + 1);
            }
        }
        
        for(Map.Entry<Integer, Integer> kv : mapa.entrySet()) {
            System.out.print(kv.getKey() + "  " + kv.getValue());
        }
        
        int counter = 0;
        for(var i : nums3) {
            for(var j : nums4) {
                counter += mapa.getOrDefault(-(i+j), 0);
            }
        }
        return counter;
    }
}
