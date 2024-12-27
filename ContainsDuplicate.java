class Solution {
    public boolean containsDuplicate(int[] nums) {
        Set<Integer> skup = new HashSet<Integer>();
        for(int key : nums) {
            if(skup.contains(key)) {
                return true;
            }
            skup.add(key);
        }
        return false;
    }
}
