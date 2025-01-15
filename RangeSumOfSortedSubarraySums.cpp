class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        std::vector<int> res((n * (n+1)) / 2);
        int idx{};
        for(int i=0; i<n; i++) {
            int sum{};
            for(int j=i; j<n; j++) {
                sum += nums[j];
                res[idx] = sum;
                idx++;
            }
        }
        std::sort(res.begin(), res.end());
        // for(auto x : res) {
        //     std::cout << x << "   ";
        // }
        int sum{};
        while(left <= right) {
            sum = (sum + res[left-1]) % static_cast<int>(7 + 1e9);
            left++;
        }
        return sum;
    }
};
