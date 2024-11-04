static const bool __bost = []() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return std::ios_base::sync_with_stdio(false);
};

class Solution {
private:
    void dfs(std::set<int> &v, std::vector<std::vector<int>> &rooms, int key) {
        if(v.insert(key).second) {
            for(auto roomKey : rooms[key]) {
                dfs(v, rooms, roomKey);
            }
        }
    }
    
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        std::set<int> visited;
        // std::queue<int> red{};
        
//         visited.insert(0);
//         red.push(0);
//         while(!red.empty()) {
//             for(auto key : rooms[red.front()]) {
//                 if(visited.insert(key).second) {
//                     red.push(key);
//                 }
//             }
//             red.pop();
//         }
            
        dfs(visited, rooms, 0);
        return visited.size() == rooms.size();
    }
};
