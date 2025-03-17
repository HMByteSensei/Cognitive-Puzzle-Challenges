public class Solution {
    private void helper2(ref IList<int> rez, int i, int j = 1, int t = 0, int tmp = 1) {
        if(i + 1 == j) {
            return;
        }
        if(i == j) {
            rez[j] = 1;
        }
        rez[j-1] = tmp + t;
        helper2(ref rez, i, j+1, tmp, rez[j]);
    }
    
    private IList<int> helper(ref IList<int> rez, int i) {
        if(rez.Count == i) {
            return rez;
        }
        // int tmp = 1;
        // int t = 0;
        // for(int j=1; j<=i; j++) {
        //     if(i==j) {
        //         rez[j] = 1;
        //     }
        //     rez[j - 1] = tmp + t;
        //     t = tmp;
        //     tmp = rez[j];
        // }
        helper2(ref rez, i);
        helper(ref rez, i + 1);
        return rez;
    }
    
    public IList<int> GetRow(int rowIndex) {
        IList<int> rez = new List<int>(new int[rowIndex + 1]);
        rez[0] = 1;
        helper(ref rez, 0);
        return rez;
    }
}
