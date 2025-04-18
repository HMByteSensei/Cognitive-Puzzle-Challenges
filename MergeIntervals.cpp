class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end());
        std::vector<std::vector<int>> merged{intervals[0]};
        int j = 0;
        for(int i = 1; i<intervals.size(); i++) {
            int firstMerged = merged[j][0];
            int secondMerged = merged[j][1];
            int firstInter = intervals[i][0];
            int secondInter = intervals[i][1];
            if(secondMerged >= firstInter) {
                merged[j][1] = (secondInter > secondMerged) ? secondInter : secondMerged;
            } else {
                merged.push_back({firstInter, secondInter});
                j++;
            }
        }
        return merged;
    }
};
