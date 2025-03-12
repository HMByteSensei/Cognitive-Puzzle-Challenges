
class Solution {
public:
    int heightChecker(vector<int>& heights) {
        std::ios::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::vector<int> rez(heights.begin(), heights.end());
        for(int i=0; i<rez.size()-1; i++) {
            for(int j=i+1; j<rez.size(); j++) {
                if(rez[i] > rez[j]) {
                    std::swap(rez[i], rez[j]);
                }
            }
        }
        int num{};
        for(int i=0; i<rez.size(); i++) {
            if(rez[i] != heights[i]) {
                num++;
            }
        }
        return num;
    }
};
