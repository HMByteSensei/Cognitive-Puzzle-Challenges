#pragma GCC optimize("O3,unroll-loops")

static const bool __boost = [](){
    cin.tie( nullptr );
    cout.tie( nullptr );
    return ios_base::sync_with_stdio( false );
}();

class Solution {
// private:
//     void recursionHelper(int i, int j, std::vector<char> &s) {
//         if(i >= j) {
//             return;
//         }
//         std::swap(s[i], s[j]);
//         recursionHelper(i+1, j-1, s);
//     }
    
public:
    void reverseString(vector<char>& s) {
        // Iterative:
        for(int i=0, j=s.size() - 1; i<j; i++, j--) {
            int tmp = s[i];
            s[i] = s[j];
            s[j] = tmp;
        }
        
        // Recursion:
        // recursionHelper(0, s.size() - 1, s);    
    }
};
