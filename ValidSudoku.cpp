class Solution {
private:
    bool isNum(char n) {
        return n >= '0' && n <= '9';
    }
    
    bool tileCheck(int rowStart, int colStart, std::vector<std::vector<char>>& board, std::unordered_set<char>& skup) {
        for(int i = rowStart; i < rowStart + 3; i++) {
            for(int j = colStart; j < colStart + 3; j++) {
                if(isNum(board[i][j])) { 
                    if(skup.find(board[i][j]) == skup.end()) {
                        skup.insert(board[i][j]);
                    } else {
                        return false;
                    }
                }
            }
        }
        return true;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        std::unordered_set<char> skup;
        
        // row check
        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) {
                if(isNum(board[i][j])) { 
                    if(skup.find(board[i][j]) == skup.end()) {
                        skup.insert(board[i][j]);
                    } else {
                        // std::cout << *skup.find(board[j][i]);
                        return false;
                    }
                }
            }
            skup.clear();
        }
        
        // column check
        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) {
                if(isNum(board[j][i])) { 
                    if(skup.find(board[j][i]) == skup.end()) {
                        skup.insert(board[j][i]);
                    } else {
                        // std::cout << *skup.find(board[j][i]);
                        return false;
                    }
                }
            }
            skup.clear();
        }
        
        // tile check
        for(int i = 0; i < 9; i += 3) {
            for(int j = 0; j < 9; j += 3) {
                if(!tileCheck(i, j, board, skup)) {
                    return false;
                }
                skup.clear();
            }
        }
        
        return true;
    }
};
