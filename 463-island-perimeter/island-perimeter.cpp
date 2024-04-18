class Solution {
public:
    int point(int r, int c, int row, int col) {
        return r * col + c;
    }
    bool safe(int r, int c, int row, int col) {
        return r >= 0 && r < row && c >= 0 && c < col;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        int ans = 0;
        vector<bool> vis(row*col, false);

        int dx[] = {1,0,-1,0};
        int dy[] = {0,1,0,-1};

        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(grid[i][j] == 1) {
                    queue<int> bfs;
                    int f_point = point(i,j,row,col);
                    bfs.push(f_point);
                    vis[f_point] = true;
                    
                    while(!bfs.empty()) {
                        f_point = bfs.front();
                        bfs.pop();
                        ans+= 4;
                        int cur_x = f_point/col, cur_y = f_point % col;
                        for(int k = 0; k < 4; k++) {
                            int nx = cur_x + dx[k];
                            int ny = cur_y + dy[k];
                            if(safe(nx,ny,row,col) && grid[nx][ny] == 1) {
                                ans--;
                                if(!vis[point(nx,ny,row,col)]) {
                                    bfs.push(point(nx,ny,row,col));
                                    vis[point(nx,ny,row,col)] = true;
                                }
                                    
                            }
                        }
                    }
                    return ans;
                    
                } 
            }
        }
        return ans;
    }
};