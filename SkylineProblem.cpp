class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        std::multiset<int> pq{0};
        std::vector<std::vector<int>> rez{};
        std::vector<std::pair<int, int>> points{};
        
        for(auto b : buildings) {
            points.push_back(std::make_pair(b[0], -b[2]));
            points.push_back(std::make_pair(b[1], b[2]));
        }
        
        int maxHeight{};
        std::sort(points.begin(), points.end());
        
        for(int i=0; i<points.size(); i++) {
            int currentPoint = points[i].first;
            int currentHeight = points[i].second;
            
            if(currentHeight < 0) {
                pq.insert(-currentHeight);
            } else {
                pq.erase(pq.find(currentHeight));
            }
            int pqTop = *std::prev(pq.end());
            if(maxHeight != pqTop) {
                maxHeight = pqTop;
                rez.push_back({currentPoint, maxHeight});
            }
        }
        return rez;
    }
};
