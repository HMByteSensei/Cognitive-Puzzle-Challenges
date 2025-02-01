class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        std::vector<std::vector<int>> rez{};
        std::vector<int> combination;
        std::sort(candidates.begin(), candidates.end()); 

        findCombinations(candidates, target, 0, combination, rez);
        return rez;
    }

private:
    void findCombinations(const vector<int>& candidates, int target, int start, vector<int>& combination, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(combination);
            return;
        }
        
        for (int i = start; i < candidates.size(); ++i) {
            if (i > start && candidates[i] == candidates[i - 1]) {
                continue; // Skip duplicates
            }
            
            if (candidates[i] > target) {
                break;
            }
            
            combination.push_back(candidates[i]);
            findCombinations(candidates, target - candidates[i], i + 1, combination, result); // Move to the next index
            combination.pop_back(); // Backtrack
        }
    }
};
