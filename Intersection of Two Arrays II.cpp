class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        std::unordered_map<int, int> mapa;
        for(const auto &x : nums1) {
            mapa[x]++;
        }
        nums1.clear();
        for(const auto &x : nums2) {
            if(mapa[x] >= 1) {
                nums1.push_back(x);
                mapa[x]--;
            }
        }
        return nums1;
    }
};
