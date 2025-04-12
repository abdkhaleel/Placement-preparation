class Solution {
    public:
        void solveSudoku(vector<vector<char>>& board) {
            isValidSudoku(board);
        }
          bool isValid(vector<vector<char>>& board, char& c, int row, int col){
            for(int i = 0; i < 9; i++){
                if(board[row][i] == c) return false;
                if(board[i][col] == c) return false;
                if(board[3*(row/3) + i/3][3*(col/3 )+ i%3] == c) return false;
            }
            return true;
        }
        
        bool isValidSudoku(vector<vector<char>>& board) {
            for(int i = 0; i < 9; i++){
                for(int j = 0; j < 9; j++){
                    if(board[i][j] == '.'){
                        for(char c = '1'; c <= '9'; c++){
                            if(isValid(board, c, i, j)){
                                board[i][j] = c;
                                if(isValidSudoku(board)){
                                    return true;
                                }
                                board[i][j] = '.';
                            }
                        }
                        return false;
                    }
                }
            }
            return true;
        }
    };