#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

class Solution {
public:
    int longestPalindrome(string s) {
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
        std::ios_base::sync_with_stdio(false);
        std::unordered_map<char, int> mapa{};
        for(char x : s) {
            mapa[x]++;
        }
        int len{};
        bool nep = false;
        for(auto x : mapa) {
            if(x.second % 2 == 0) {
                len += x.second;
            } else if(x.second >= 3) {
                len += (x.second - 1);
                nep = true;
            } else {
                nep = true;
            }
        }
        if(nep) {
            len++;
        }
        return len;
    }
};
