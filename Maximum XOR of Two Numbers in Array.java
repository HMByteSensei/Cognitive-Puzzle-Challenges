class Trie {
    Trie[] num = new Trie[2];
    int number = 0;
    
    public void insert(int n) {
        Trie cur = this;
        for(int i=31; i>=0; i--) {
            int tmp = (n >> i) & 1;
            if(cur.num[tmp] == null) {
                cur.num[tmp] = new Trie();
            }
            cur = cur.num[tmp];
        }
        cur.number = n;
    }
}

class Solution {
    public int findMaximumXOR(int[] nums) {
        Trie root = new Trie();
        for(int n : nums) {
            root.insert(n);
        }
        int curMax = 0;
        for(int n : nums) {
            Trie tmp = root;
            int max = 0;
            for(int i=31; i>=0; i--) {
                int bit = (n >> i) & 1;
                if(tmp.num[1 - bit] != null) {
                    max = (1 << i) | max;
                    tmp = tmp.num[1-bit];
                } else {
                    tmp = tmp.num[bit];
                }
            }
            curMax = (max > curMax) ? max : curMax;
        }
        return curMax;
    }
}
