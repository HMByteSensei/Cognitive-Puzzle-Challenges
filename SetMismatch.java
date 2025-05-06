class Solution {
    public int[] findErrorNums(int[] nums) {
        int[] res = new int[2];

        for(int i=0; i<nums.length; i++) {
            int cur = Math.abs(nums[i]);
            if(nums[cur - 1] < 0) {
                res[0] = cur;
            } else {
                nums[cur - 1] =  -nums[cur - 1];
            }
        }
        for(int i=0; i<nums.length; i++) {
            if(nums[i] > 0) {
                res[1] = i+1;
                return res;
            }
        }
        return res;
    }
}
