class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        std::unordered_set<std::string> visited(deadends.begin(), deadends.end());
        // std::unordered_set<std::string> visited;
        std::queue<std::string> red;
        if(visited.count("0000") > 0) {
            return -1;
        }

        int steps{};
        red.push("0000");
        visited.insert("0000");
        while(!red.empty()) {
            int len = red.size();
            for(int i=0; i<len; i++) {
                if(red.front() == target) {
                    return steps;
                }
                for(int m=0; m<4; m++) {
                    int incDec[] = {1, -1};
                    for(int k=0; k<2; k++) {
                        std::string s = red.front();
                        int num = (static_cast<int>(s[m]) - '0') + incDec[k];
                        if(num == 10) {
                            num = 0;
                        } else if(num == -1) {
                            num = 9;
                        }
                        s[m] = '0' + num;
                        if(visited.count(s) == 0) {
                            red.push(s);
                            visited.insert(s);
                        }
                    }
                }
                red.pop();
            }
            steps++;
        }
        return -1;
    }
};
