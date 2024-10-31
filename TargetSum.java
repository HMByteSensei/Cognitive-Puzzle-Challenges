class Solution {
    private void dfs(int[] nums, int t, int i, int[] rez, int sum) {
        if(i == nums.length) {
            if(t == sum) {
                rez[0]++;
            }
            return;
        }
        dfs(nums, t, i+1, rez, sum + nums[i]);
        dfs(nums, t, i+1, rez, sum - nums[i]);
    }
    
    public int findTargetSumWays(int[] nums, int target) {
        int[] rez={0};
        
        dfs(nums, target, 0, rez, 0);
        return rez[0];
    }
}
