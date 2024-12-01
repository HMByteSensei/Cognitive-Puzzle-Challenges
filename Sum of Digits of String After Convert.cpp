class Solution {
public:
    int getLucky(string s, int k) {
        std::string rez{};
        for(char ch : s) {
            rez += std::to_string((ch - 'a') + 1);
        }
        int num{};
        while((k--) > 0) {
            num = 0;
            for(int i=0; i<rez.length(); i++) {
                num += (rez[i] - '0'); 
            }
            rez = std::to_string(num);
        }
        return num;
    }
};
