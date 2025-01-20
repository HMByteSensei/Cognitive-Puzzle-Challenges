class Solution {
private:
    int sumOfDigits(int n) {
        int sum{};
        while(n > 0) {
            int rem = n % 10;
            sum += (rem * rem);
            n /= 10;
        }
        return sum;
    }
public:
    bool isHappy(int n) {
        std::unordered_set<int> skup = {n};
        while((n = sumOfDigits(n)), n != 1) {
            if(skup.count(n) >= 1) {
                return false;
            }
            skup.insert(n);
        }
        return true;
    }
};
