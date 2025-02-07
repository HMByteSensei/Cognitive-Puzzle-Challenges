public class Solution {
    public int LengthOfLongestSubstring(string s) {
        int start = 0, rez=0;
        // a b c a b c b
        //         ^
        // rez = 3-0=3
        // mapa: (a, 3) (b, 4) (c, 2)
        Dictionary<char, int> mapa = new Dictionary<char, int>();
        for(int i=0; i<s.Length; i++) {
            if(mapa.ContainsKey(s[i])) {
                int tmp = mapa[s[i]];
                foreach(KeyValuePair<char, int> kvp in mapa) {
                    if(kvp.Value <= tmp) {
                        mapa.Remove(kvp.Key);
                    }
                }
                start = Math.Max(start, tmp + 1);
            }
            rez = Math.Max(rez, i - start+1);
            mapa[s[i]] = i;
        }
        
        return rez;
    }
}
