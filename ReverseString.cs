public class Solution {
    public void ReverseString(char[] s) {
        recursionHelper(0, s.Length-1, s);
    }
    
    private void recursionHelper(int i, int j, char[] s) {
        if(i >= j) {
            return;
        }
        char tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
        recursionHelper(i+1, j-1, s);
    }
}
