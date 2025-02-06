class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        std::unordered_map<int, int> mapa;
        
        for(int j=0; j<nums2.size(); j++) {
            for(int k=0; k<nums3.size(); k++) {
                mapa[nums2[j] + nums3[k]]++;
            }
        }
        
        int rez{};
        for(int j=0; j<nums1.size(); j++) {
            for(int m=0; m<nums4.size(); m++) {
                rez += mapa[- (nums1[j] + nums4[m])];
            }
        }
        return rez;
    }
};
