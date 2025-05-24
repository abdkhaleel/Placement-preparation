class Solution {
private:
    int n;
    int m;
    vector<pair<int, int>> dir = {{0, -1}, {-1, 0}, {1, 0}, {0, 1}};
    void dfs(int row, int col, vector<vector<char>>& grid, vector<vector<bool>>& vis){
        vis[row][col] = true;
        stack<pair<int, int>> st;
        st.push({row, col});
        while(!st.empty()){
            auto [r, c] = st.top();
            st.pop();
            for(auto& [dr, dc]: dir){
                int nr = r + dr;
                int nc = c + dc;
                if(nr >= 0 && nc >= 0 && nr < n && nc < m && grid[nr][nc] == '1' && !vis[nr][nc]){
                    vis[nr][nc] = true;
                    st.push({nr, nc});
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int count = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    dfs(i, j, grid, vis);
                    count++;
                }
            }
        }

        return count;
    }
};