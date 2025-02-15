class Solution {
public:
    int appendCharacters(string s, string t) {
       std::cin.tie(nullptr);
       std::cout.tie(nullptr);
       std::ios_base::sync_with_stdio(false);
       int j=0;
       for(int i=0; i<s.length(); i++) {
            if(s[i] == t[j]) {
                j++;
            }
       }
       return t.length() - j;
    }
};
