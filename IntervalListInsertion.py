public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        std::vector<std::vector<int>> merged{};
        int n = firstList.size(), m = secondList.size();
        for(int i=0, j=0; i<n && j<m;) {
            int firstSmall = firstList[i][0];
            int firstBig = firstList[i][1];
            int secondSmall = secondList[j][0];
            int secondBig = secondList[j][1];
            
            if(firstSmall <= secondBig && secondSmall <= firstBig) {
                merged.push_back({std::max(firstSmall, secondSmall), std::min(firstBig, secondBig)});
            } 

            if(firstBig <= secondBig) { i++; }
            else j++;
        }
        return merged;
    }
