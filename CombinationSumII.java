class Solution {
    private void helper(List<List<Integer>> rez, int target, ArrayList<Integer> current, int[] candidates, int start) {
        if(target == 0) {
            rez.add(new ArrayList<>(current));
        }

        for(int i = start; i<candidates.length; i++) {
            if(i > start && candidates[i-1] == candidates[i]) {
                continue;
            }
            if(target < 0) {
                return;
            }
            
            current.add(candidates[i]);
            helper(rez, target - candidates[i], current, candidates, i+1);
            current.remove(current.size()-1);
        }
    }
    
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        Arrays.sort(candidates);

        List<List<Integer>> rez = new ArrayList<>();
        ArrayList<Integer> current = new ArrayList<>();
        helper(rez, target, current, candidates, 0);
        return rez;
    }
}
