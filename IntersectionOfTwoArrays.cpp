class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        std::unordered_set<int> rez(nums1.begin(), nums1.end());
        nums1.clear();
        for(int i=0; i<nums2.size(); i++) {
            if(rez.count(nums2[i]) >= 1) {
                nums1.push_back(nums2[i]);
                rez.erase(nums2[i]);
            }
        }
        return nums1;
    }
};
