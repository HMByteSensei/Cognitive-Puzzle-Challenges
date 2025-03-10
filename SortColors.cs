public class Solution {
    private void loop(int[] nums, ref int i, int n0, int v=0) {
        while(n0 > 0) {
            nums[i] = v;
            n0--;
            i++;
        }
    }
    public void SortColors(int[] nums) {
        int n0 = 0, n1 = 0, n2 = 0;
        for(int i=0; i<nums.Length; i++) {
            if(nums[i] == 0) {
                n0++;
            } else if(nums[i] == 1) {
                n1++;
            } else {
                n2++;
            }
        }
        int j=0;
        loop(nums, ref j, n0);
        loop(nums, ref j, n1, 1);
        loop(nums, ref j, n2, 2);
    }
}
