public class Solution {
    public int KthGrammar(int n, int k) {
        // if(n == 1) {
        //     return 0;
        // }
        // int len_n = 1 << (n-1);
        // if(len_n / 2 >= k) {
        //     return KthGrammar(n-1, k);
        // }
        // return 1 - KthGrammar(n-1, k - len_n / 2);
        n = 0;
        k--;
        while(k >= 1) {
            if(k % 2 == 1) {
                n++;
            }
            k /= 2;
        }
        // Console.WriteLine(n);
        return (n % 2 == 0) ? 0 : 1;
    }
}
