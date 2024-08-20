#include <iostream>
#include <vector>
using namespace std;
class OutOfContext {
public:
    void rotate(vector<int>& nums, int k) {
        int m = nums.size() - (k % nums.size());
        if(m == 0 || m == nums.size()) {
            return;
        }
        int i{};
        while(i < m) {
            while(m<nums.size()) {
                std::swap(nums[i], nums[m]);
                i++;
                m++;
            }
            m = nums.size() - (k % nums.size());
        }
        while(i < nums.size()) {
            int ostalo = nums.size() - i;
            k = (k % nums.size()) - ostalo;
            k = k % ostalo;
            if(k == 0) {
                k = ostalo;
            }
            m = nums.size() - k;
            while(m < nums.size()) {
                std::swap(nums[i], nums[m]);
                i++;
                m++;
            }
        }
    }
};

int main() {
    // Write C++ code here
    Solution s;
    std::vector<int> a{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21};
    OutOfContext.rotate(a, 29);
    std::cout << "\n";
    for(auto x:a) {
        std::cout << "   " << x;
    }
    return 0;
}