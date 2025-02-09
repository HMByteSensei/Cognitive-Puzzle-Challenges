class Solution {
private:
    int helper(const std::string &s, char c, int &l, 
              std::unordered_map<char, int> &mapa, int i) {
        if(s.length() - 1 == i) {
            mapa.insert({s[i], i});
            return 1;
        }
        
        int longest = helper(s, s[i+1], l, mapa, i+1);
        int tmp = 0;
        if(!mapa.insert({c, i}).second) {
            tmp = mapa[c];
            longest = tmp - i;
            for(auto it = mapa.begin(); it != mapa.end();) {
                if(it->second >= tmp) {
                    it = mapa.erase(it);
                } else {
                    it++;
                }
            }
            mapa[c] = i;
            
        } else {
            ++longest;
        }
        if(l < longest) {
            l = longest;
        }
        
        return longest;
    }
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty()) {
            return 0;
        }
        std::unordered_map<char, int> mapa;
        int l{1};
        int longest = helper(s, s[0], l, mapa, 0);
        return (l > longest) ? l : longest;
    }
};
