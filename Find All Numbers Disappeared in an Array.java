import java.util.*;
class Solution {
    public List<Integer> findDisappearedNumbers(int[] nums) {
        // for(int i=0; i<nums.length; ) {
        //     int currNo = nums[i];
        //     if(nums[currNo - 1] != currNo) {
        //         int temp = nums[i];
        //         nums[i] = nums[currNo - 1];
        //         nums[currNo - 1] = temp;
        //     } else {
        //         i++;
        //     }
        // }
        // List<Integer> res = new ArrayList<>();
        // for(int i=0; i<nums.length; i++) {
        //     if(nums[i] != i+1) {
        //         res.add(i+1);
        //     }
        // }
        for(int i=0; i<nums.length; i++) {
            int currNo = Math.abs(nums[i]);
            nums[currNo - 1] = -Math.abs(nums[currNo - 1]);
        }
        List<Integer> res = new ArrayList<>();
        for(int i=0; i<nums.length; i++) {
            if(nums[i] > 0) {
                res.add(i+1);
            }
        }
        return res;
    }
}
