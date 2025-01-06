class Solution {
private:
    double helper(double x, long long n) {
        if (n == 0) {
            return 1.0;
        }
        if (n == 1) {
            return x;
        }

        double half = helper(x, n / 2);

        if (n % 2 == 0) {
            return half * half;
        } else {
            return half * half * x;
        }
    }

public:
    double myPow(double x, int n) {
        long long N = n;
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }
        return helper(x, N);
    }
};


// class Solution {
// private:
//     double helper(double &x, int n, double copy) {
//         if(n == 1) {
//             return x;
//         }
//         x = x*copy;
//         return helper(x, n-1, copy);
//     }
// public:
//     double myPow(double x, int n) {
//         if(n==0) {
//             return 1;
//         } else if(std::abs(x) == 1) {
//             return x;
//         }
//         double rez = helper(x, std::abs(n), x);
//         if(n < 0) {
//             return 1 / rez;
//         }
//         return rez;
//     }
// };


// class Solution {
// public:
//     double myPow(double x, int n) {
//         if(n==0) {
//             return 1;
//         }
//         long long N = n;
//         if(n < 0) {
//             N = -N;
//         }
//         double rez{x};
//         while(N > 1) {
//             rez = x * rez;
//             N--;
//         }
//         if(n < 0) {
//             return 1/rez;
//         }
//         return rez;
//     }
// };
