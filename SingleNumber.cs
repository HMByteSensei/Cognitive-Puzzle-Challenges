public class Solution {
    public int SingleNumber(int[] nums) {
        // int rez = nums[0];
        // for(int i=1; i<nums.Length; i++) {
        //     rez = rez ^ nums[i];
        // }
        // return rez;
        HashSet<int> rez = new HashSet<int>();
        for(int i=0; i<nums.Length; i++) {
            if(rez.Contains(nums[i])) {
                rez.Remove(nums[i]);
            } else {
                rez.Add(nums[i]);
            }
        }
        return (int)rez.First();
    }
}
