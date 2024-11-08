class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int num = image[sr][sc];
        if(num == color) {
            return image;
        }
        std::queue<std::pair<int, int>> red{};
        red.push({sr, sc});
        image[sr][sc] = color;
        int directions[][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        while(!red.empty()) {
            auto [row, col] = red.front();
            for(auto d : directions) {
                int newRow = row + d[0];
                int newCol = col + d[1];
                if(newRow >= 0 && newRow < image.size()
                   && newCol >= 0 && newCol < image[0].size()
                   && image[newRow][newCol] == num) {
                    red.push({newRow, newCol});
                    image[newRow][newCol] = color;
                }
            }
            red.pop();
        }
        return image;
    }
};
