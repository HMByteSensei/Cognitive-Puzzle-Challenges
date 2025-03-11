class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        std::map<int, int> mapa{};
        for(int x : arr1) {
            mapa[x]++;
        }
        int j=0, i=0;
        std::vector<int> rez(arr1.size(), 0);
        for(; j<arr2.size();) {
            do {
                rez[i] = arr2[j];
                mapa[arr2[j]]--;
                i++;
            } while(mapa[arr2[j]] > 0);
            j++;
        }
        for(std::map<int, int>::iterator it = mapa.begin(); it != mapa.end(); it++) {
            while(it->second > 0) {
                rez[i++] = it->first;
                it->second--;
            }
        }
        return rez;
    }
};
