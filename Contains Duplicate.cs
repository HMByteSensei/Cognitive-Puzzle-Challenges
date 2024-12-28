public class Solution {
    public bool ContainsDuplicate(int[] nums) {
        HashSet<int> skup = new HashSet<int>();
        foreach(int key in nums) {
            if(skup.Contains(key)) {
                return true;
            }
            skup.Add(key);
        }
        return false;
    }
}
