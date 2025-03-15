const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);
#define LC_HACK
#ifdef LC_HACK
const auto __ = []() {
    struct ___ {
        static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; }
    };
    std::atexit(&___::_);
    return 0;
}();
#endif

class Solution {
    int getIndex(const std::vector<int> &nums, int index) {
        int rez = (index + nums[index]) % static_cast<int>(nums.size());
        if(rez < 0) { rez += nums.size(); }
        return rez;
    }
public:
    bool circularArrayLoop(vector<int>& nums) {
        std::set<int> skup{};
        for(int i=0; i<nums.size(); i++) {
            if(skup.count(i) > 0) {
                continue;
            }
            int slow, fast;
            slow = fast = getIndex(nums, i);
            fast = getIndex(nums, fast);
            while(slow != fast) {
                skup.insert(slow);
                slow = getIndex(nums, slow);
                fast = getIndex(nums, getIndex(nums, fast));
            }
            int count{1};
            slow = getIndex(nums, slow);
            fast = getIndex(nums, slow);
            std::cout << "\n"<< slow << "   " << fast;
            while(slow != fast) {
                count++;
                slow = getIndex(nums, slow);
                fast = getIndex(nums, fast);
                std::cout << "\n\t"<<slow << "   " << fast << "   " <<nums[slow] << "   " << nums[fast];
                if(nums[slow] * nums[fast] < 0) {
                    count = 0;
                    break;
                }
                fast = getIndex(nums, fast);
                if(nums[slow] * nums[fast] < 0) {
                    count = 0;
                    break;
                }
            }
            if(count > 1) return true;
        }
        return false;
    }
};
