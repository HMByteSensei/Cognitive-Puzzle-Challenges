class Solution {
    public int firstMissingPositive(int[] nums) {
        boolean one = false;
        for(int i=0; i<nums.length; i++) {
            if(nums[i] == 1) {
                one = true;
            }
            if(nums[i] <= 0 || nums[i] > nums.length) {
                nums[i] = 1;
            }
        }

        if(!one) {
            return 1;
        }

        for(int i=0; i<nums.length;) {
            int curr = nums[i];
            if(nums[curr - 1] != curr) {
                nums[i] = nums[curr - 1];
                nums[curr - 1] = curr;
            } else {
                i++;
            }
        }
        int i = 0;
        for(; i<nums.length; i++) {
            if(nums[i] != i+1) {
                return i+1;
            }
        }
        return i+1;
    }
}
