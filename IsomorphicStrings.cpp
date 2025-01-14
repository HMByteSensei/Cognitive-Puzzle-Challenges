class Solution {
private:
    bool helper(std::unordered_map<char, char> &s_map, const std::string &s, std::string &t, int i) {
        if(s_map.find(s[i]) != s_map.end()) {
            if(s_map[s[i]] != t[i]) {
                return false;
            } 
        } else {
            s_map[s[i]] = t[i];
        }
        return true;
    }
public:
    bool isIsomorphic(string s, string t) {
        std::unordered_map<char, char> s_map;
        std::unordered_map<char, char> t_map;
        for(int i=0; i<s.length(); i++) {
            if(!helper(s_map, s, t, i)) {
                return false;
            }
            if(!helper(t_map, t, s, i)) {
                return false;
            }
        }
        
        return true;
    }
};
