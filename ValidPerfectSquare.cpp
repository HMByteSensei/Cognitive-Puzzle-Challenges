class Solution {
public:
    bool isPerfectSquare(int num) {
        int L = 0, R = num;
        
        while(L < R) {
            int mid = L + (R - L) / 2 + 1;
            if(std::numeric_limits<int>::max() / mid < mid) {
                R = mid - 1;
                continue;
            }
            
            int square = mid * mid;
            
            if(square == num) {
                return true;
            } else if(square > num) {
                R = mid - 1;
            } else {
                L = mid;
            }
        }
        return false;
    }
};
