class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        std::unordered_map<std::string, int> mapa;
        if(arr.size() == k) {
            for(const std::string &s : arr) {
                mapa[s]++;
                if(mapa[s] > 1) {
                    return "";
                }
            }
            return arr[arr.size() - 1];
        }
        for(const std::string &s : arr) {
            mapa[s]++;
        }
        int counter{};
        for(const auto &s : arr) {
            if(mapa[s] == 1) {
                counter++;
                if(counter == k) {
                    return s;
                }
            }
        }
        return "";
    }
};
