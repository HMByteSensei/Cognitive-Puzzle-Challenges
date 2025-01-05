public class Solution {
    public double helper(double x, long n, double res = 0) {
        if(n == 1) {
            return x;
        }
        double half = helper(x, n / 2);
        if(n % 2 == 0) {
            return half * half;
        }
        return half * half * x;
    }
    public double MyPow(double x, int n) {
        if(n == 0) {
            return 1;
        }
        long N = n;
        if(n < 0) {
            N = -N;
            x = 1/x;
        }
        return helper(x, N);
    }
}
