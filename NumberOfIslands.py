from queue import Queue

class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        visited = set();
        islands = 0;
        
        def bfs(i , j):
            red = Queue();
            red.put((i,j));
            visited.add((i,j))
            while not red.empty():
                directions = [[1, 0], [-1, 0], [0,1], [0,-1]];
                
                [currentRow, currentCol] = red.get();
                for i in range(4):
                    row = currentRow + directions[i][0];
                    col = currentCol + directions[i][1];
                    
                    if(row in range(0, len(grid)) and col in range(0, len(grid[0])) and grid[row][col] == '1' and (row, col) not in visited):
                        visited.add((row, col));
                        red.put((row, col));
        
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if( grid[i][j] == '1' and (i, j) not in visited ):
                    bfs(i , j);
                    islands += 1;
                    
        return islands;
