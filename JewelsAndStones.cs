public class Solution {
    public int NumJewelsInStones(string jewels, string stones) {
        HashSet<char> skup = new HashSet<char>();
        
        for(int i=0; i<jewels.Length; i++) {
            skup.Add(jewels[i]);
        }
        int c = 0;
        for(int i=0; i<stones.Length; i++) {
            if(skup.Contains(stones[i])) {
                c++;
            }
        }
        return c;
    }
}
