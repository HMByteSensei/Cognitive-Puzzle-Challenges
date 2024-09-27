class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int br{};
        for(int i=1; i<nums.size(); i++) {
            if(nums[i] == nums[i-1]) {
                i++;
            } else {
                nums[br] = nums[i-1];
                br++;
            }
        }
        if(nums[nums.size() - 2] != nums[nums.size()-1]) {
            nums[br] = nums[nums.size() - 1];
            br++;
        }
        nums.resize(br);
        return nums;
    }
};