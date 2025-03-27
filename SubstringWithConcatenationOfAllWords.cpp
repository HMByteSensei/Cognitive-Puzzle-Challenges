// class Solution {
// public:
//     vector<int> findSubstring(string s, vector<string>& words) {
//         vector<int> res;
//         if (words.empty() || s.empty()) return res;

//         int wordLen = words[0].length();
//         int numWords = words.size();
//         int totalLen = wordLen * numWords;
//         if (totalLen > s.length()) return res;

//         unordered_map<string, int> wordCount;
//         for (const string& word : words) {
//             wordCount[word]++;
//         }

//         // Try every possible starting point within the word length
//         for (int i = 0; i < wordLen; i++) {
//             int left = i, count = 0;
//             unordered_map<string, int> seen;

//             for (int right = i; right + wordLen <= s.length(); right += wordLen) {
//                 string currWord = s.substr(right, wordLen);

//                 if (wordCount.find(currWord) != wordCount.end()) {
//                     seen[currWord]++;
//                     count++;

//                     // If this word appears too many times, remove from left
//                     while (seen[currWord] > wordCount[currWord]) {
//                         string leftWord = s.substr(left, wordLen);
//                         seen[leftWord]--;
//                         left += wordLen;
//                         count--;
//                     }

//                     // If we have all words matched, store the start index
//                     if (count == numWords) {
//                         res.push_back(left);
//                     }
//                 } else {
//                     // Reset window if invalid word is encountered
//                     seen.clear();
//                     count = 0;
//                     left = right + wordLen;
//                 }
//             }
//         }
//         return res;
//     }
// };

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res{};
        if (words.empty() || s.empty()) return res;

        std::unordered_map<std::string, int> mapa{};
        for(const std::string &w : words) {
            mapa[w]++;
        }
        int wordLen = words[0].length();
        int numWords = words.size();
        int totalLen = wordLen * numWords;
        for(int i=0; i<wordLen; i++) {
            int begin = i, end = i; 
            int counter = words.size();

            while(end < s.size()) {
                std::string currWord = s.substr(end, wordLen);

                if(mapa.find(currWord) != mapa.end()) {
                    if(mapa[currWord]-- > 0) { counter--; }

                    while(mapa[currWord] < 0) {
                        std::string beginWord = s.substr(begin, wordLen);
                        if(mapa.find(beginWord) != mapa.end()) {
                            mapa[beginWord]++;
                            if(mapa[beginWord] > 0) counter++;
                        }
                        begin += wordLen;
                    }

                    if(counter == 0) {
                        res.push_back(begin);
                        while(counter == 0) {
                            std::string beginWord = s.substr(begin, wordLen);
                            mapa[beginWord]++;
                            if(mapa[beginWord] > 0) counter++;
                            begin += wordLen;
                        }
                    }
                } else {
                    while(begin <= end) {
                        std::string beginWord = s.substr(begin, wordLen);
                        if(mapa.find(beginWord) != mapa.end()) {
                            mapa[beginWord]++;
                            if(mapa[beginWord] > 0) counter++;
                        }
                        begin += wordLen;
                    }
                }
                end += wordLen;
            }
        }
        return res;
    }
};
