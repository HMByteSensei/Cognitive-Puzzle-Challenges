class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> mapa;
        for(const auto &x : nums) {
            mapa[x]++;
        }
        
        std::multimap<int, int> mapa2;
        for(auto it = mapa.begin(); it != mapa.end(); it++) {
            mapa2.insert({it->second, it->first});
        }
        nums.clear();
        for(auto it = mapa2.rbegin(); it != mapa2.rend() && k > 0; it++) {
            if(k > 0) {
                nums.push_back(it->second);
                k--;
            }
        }
        return nums;
    }
};
