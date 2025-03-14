#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

static const bool __boost = [](){
    cin.tie( nullptr );
    cout.tie( nullptr );
    return ios_base::sync_with_stdio( false );
}();

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(groupSize == 1) return true;
        std::sort(hand.begin(), hand.end());
        for(int i=0; i<hand.size(); i++) {
            int k=i, m;
            if(k >= hand.size() - 1) return false;
            for(int j=0; j<groupSize-1; j++) {
                if(k >= hand.size() - 1) { 
                    return false;
                }
                while(k<hand.size() - 1 && hand[k] == -1) { k++; }
                m = k + 1;
                while(m<hand.size() && hand[m] == -1) { m++; }
                if(m >= hand.size() && hand[m-1]==-1) return false;
                // std::cout << k << "  "<<m;
                if(hand[k] + 1 != hand[m]) {
                    j--;
                } else {
                    hand[k] = -1;
                }
                // std::cout << "k: " <<k << ", and hand[k]: "<<hand[k]<<"  ";
                // std::cout << "m: " <<m << ", and hand[m]: "<<hand[m]<<"\n";
                k++;
            }
            if(hand.size() > m) {
                hand[m] = -1;
            } else {
                return false;
            }
            while(i<hand.size() && hand[i] == -1) {
                // std::cout << "i: " <<i << ", and hand[i]: "<<hand[i]<<"\n";
                i++;
            }
            i--;
        }
        return true;
    }
};
