class Solution {
    public:
        void f(int col, vector<string>& board, vector<vector<string>>& ans,
                    vector<bool>& left, vector<bool>& upper, 
                    vector<bool>& lower, int n){
    
            if(n == col){
                ans.push_back(board);
                return;
            }
            for(int row = 0; row < n; row++){
                if(left[row] && upper[row+col] && lower[n-1 + col-row]){
                    left[row] = 0;
                    upper[row+col] = 0;
                    lower[n-1 + col-row] = 0;
                    board[row][col] = 'Q';
                    f(col+1, board, ans, left, upper, lower, n);
                    left[row] = 1;
                    upper[row+col] = 1;
                    lower[n-1 + col-row] = 1;
                    board[row][col] = '.';
                }
            }
    
    
        }
        vector<vector<string>> solveNQueens(int n) {
            vector<vector<string>> ans;
            vector<string> board(n, string(n, '.'));
            vector<bool> left(n, 1), upper(2*n, 1), lower(2*n, 1);
            f(0, board, ans, left, upper, lower, n);
            return ans;
        }
    };