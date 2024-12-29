class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::unordered_set<int> skup{};
        for(int key : nums) {
            if(skup.count(key) >= 1) {
                return true;
            }
            skup.insert(key);
        }
        return false;
    }
};
