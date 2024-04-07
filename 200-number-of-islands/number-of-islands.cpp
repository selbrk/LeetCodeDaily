class Solution {
public:
    int dr[4] = {0,0,-1,1}, dc[4] = {1,-1,0,0};
    int row, col;
    bool safe(int r, int c) {
        return r >= 0 && r < row && c>=0 && c < col;
    }
    void dfs(vector<vector<char>>& grid, int r, int c) {
        grid[r][c] = 0;
        for(int i = 0; i<4; i++) {
            int nr = r + dr[i], nc = c + dc[i];
            if(safe(nr,nc) && grid[nr][nc] == '1') 
                dfs(grid,nr,nc);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        row = grid.size(), col = grid[0].size();
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(grid[i][j] == '1') {
                    ans++;
                    dfs(grid, i, j);
                }
            }
        }

        return ans;

    }
};