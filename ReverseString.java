class Solution {
    public void reverseString(char[] s) {
        recursionHelper(0, s.length-1, s);
    }
    
    public void recursionHelper(int i, int j, char[] s) {
        if(i >= j) {
            return;
        }
        char tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
        recursionHelper(i+1, j-1, s);
    }
}
