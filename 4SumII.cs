public class Solution {
    public int FourSumCount(int[] nums1, int[] nums2, int[] nums3, int[] nums4) {
        Dictionary<int, int> mapa = new Dictionary<int, int>();
        
        foreach(int i in nums1) {
            foreach(int j in nums2) {
                if(mapa.ContainsKey(i+j)) {
                    mapa[i+j]++;
                } else {
                    mapa[i+j] = 1;
                }
            }
        }
        
        int counter = 0;
        foreach(int i in nums3) {
            foreach(int j in nums4) {
                if(mapa.TryGetValue(-(i+j), out int c))
                counter += c;
            }
        }
        return counter;
    }
}
