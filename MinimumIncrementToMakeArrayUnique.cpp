class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int rez{};
        for(int i=1; i<nums.size(); i++) {
            if(nums[i-1] >= nums[i]) {
                nums[i]++;
                rez++;
                i--;
            }
        }
        return rez;
    }
};
