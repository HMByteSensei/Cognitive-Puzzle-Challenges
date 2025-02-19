#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
        std::ios_base::sync_with_stdio(false);
        std::unordered_map<char, int> mapa{};
        for(auto ch : words[0]) {
            mapa[ch]++;
        }
        for(int i=1; i<words.size(); i++) {
            std::unordered_map<char, int> rez{};
            for(auto ch : words[i]) {
                if(mapa[ch] > 0) {
                    mapa[ch]--;
                    rez[ch]++;
                }
            }
            mapa = rez;
        }
        // for(auto x : mapa) {
        //     std::cout << x.first << "  " <<x.second << "\n";
        // }
        std::vector<std::string> rez{};
        for(auto x : mapa) {
            while(x.second > 0) {
                rez.push_back(std::string(1, x.first));
                x.second--;
            }
        }
        return rez;
    }
};
