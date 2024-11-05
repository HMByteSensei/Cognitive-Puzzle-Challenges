class Solution {
public:
    string decodeString(string s) {
        std::stack<std::string> sta{};
        
        for(int i=0; i<s.length(); i++) {
            if(s[i] == ']') {
                std::string tmp{};
                while(!sta.empty() && sta.top() != "[") {
                    tmp = sta.top() + tmp;
                    sta.pop();
                }
                sta.pop();
                std::string num{};
                while(!sta.empty() && (sta.top()[0] >= '0' && sta.top()[0] <= '9')) {
                    num = sta.top() + num;
                    sta.pop();
                }
                int number = std::stoi(num);
                std::string rez{};
                while(number > 0) {
                    rez += tmp;
                    number--;
                }
                sta.push(rez);
            } else {
                sta.push(std::string(1, s[i]));
            }
        }
        std::string rez{};
        while(!sta.empty()) {
            rez = sta.top() + rez;
            sta.pop();
        }

        return rez;
    }
};
