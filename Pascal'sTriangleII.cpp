#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

static const bool __boost = [](){
    cin.tie( nullptr );
    cout.tie( nullptr );
    return ios_base::sync_with_stdio( false );
}();

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        std::vector<int> rez(rowIndex+1, 0);
        rez[0] = 1;
        for(int i=1; i<=rowIndex; i++) {
            int tmp{1};
            for(int j=1; j<=i; j++) {
                if(j == i) {
                    rez[j] = 1;
                }
                int t = rez[j-1];
                rez[j-1] = tmp;
                tmp = rez[j] + t;
            }
        }
        return rez;
    }
};
