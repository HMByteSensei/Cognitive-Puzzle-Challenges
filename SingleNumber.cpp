class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // int rez{nums[0]};
        // for(int i=1; i<nums.size(); i++) {
        //     rez = rez ^ nums[i];
        // }
        // return rez;
        
        std::unordered_set<int> rez;
        for(int key : nums) {
            if(rez.count(key) >= 1) {
                rez.erase(key);
            } else {
                rez.insert(key);
            }
        }
        // std::unordered_set<int>::iterator r = rez.begin();
        return *rez.begin();;
    }
};
