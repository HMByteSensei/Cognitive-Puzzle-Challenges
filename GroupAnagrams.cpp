class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> mapa;
        
        for ( std::string s : strs ) {
            std::string original = s;
            std::sort(s.begin(), s.end());
            mapa[s].push_back(original);
        }
        
        std::vector<std::vector<std::string>> matrix;
        
        for(auto &vec : mapa) {
            std::sort(vec.second.begin(), vec.second.end());
            matrix.push_back(vec.second);
        }
        return matrix;
    }
};
