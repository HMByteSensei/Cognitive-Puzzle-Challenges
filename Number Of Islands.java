import java.util.Map.Entry;
import java.util.AbstractMap;

class Solution {
    HashSet<String> visited;
    Queue<Entry<Integer, Integer>> red;

    private void bfs(int i, int j, char[][] grid) {
        red.offer(new AbstractMap.SimpleEntry<>(i, j));
        visited.add(Integer.toString(i) +"," +Integer.toString(j));
        
        while(!red.isEmpty()) {
            int[][] directions = { {1, 0}, {-1, 0}, {0,1}, {0,-1}};
            
            Entry<Integer, Integer> current = red.poll();
            int currRow = current.getKey();
            int currCol = current.getValue();
            for(int k=0; k<4; k++) {
                int row = currRow + directions[k][0];
                int col = currCol + directions[k][1];
                String curr = Integer.toString(row) +"," +Integer.toString(col);
                
                if(row >= 0 && row < grid.length && col >= 0 && col < grid[0].length && grid[row][col] == '1' && !visited.contains(curr)) {
                    visited.add((new String(curr)));
                    red.offer(new AbstractMap.SimpleEntry<>(row, col));
                }
            }
        
        }
    }
//     private boolean isValid(char[][] grid, int i, int j) {
//         return (i >= 0 && i < grid.length && j >= 0 && j < grid[0].length
//                && grid[i][j] == '1');
//     }
    
//     private void dfs(int i, int j, char[][] grid) {
//         int directions[][] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
//         for(int k=0; k<4; k++) {
//             int row = i + directions[k][0];
//             int col = j + directions[k][1];
//             String str = Integer.toString(row) + "," + Integer.toString(col);
            
//             if(isValid(grid, row, col) && !visited.contains(str)) {
//                 visited.add(str);
//                 dfs(row, col, grid);
//             }
//         }
        
//     }
    
    public int numIslands(char[][] grid) {
        visited = new HashSet<>();
        red = new LinkedList<>();
        
        int islands = 0;
        
        for(int i=0; i<grid.length; i++) {
            for(int j=0; j<grid[0].length; j++) {
                if(grid[i][j] == '1' && !visited.contains(Integer.toString(i) + "," + Integer.toString(j))) {
                    // visited.add(Integer.toString(i) + "," + Integer.toString(j));
                    // dfs(i, j, grid);
                    bfs(i, j, grid);
                    islands++;
                }
            }
        }
        
        return islands;
    }
};
