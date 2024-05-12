class Solution {
public:
    bool safe(int r, int c, int n) {
        return r > 0 && c > 0 && r < n-1 && c < n-1;
    }


    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> ans(n-2, vector<int>(n-2));
        int dx[] = {1,0,-1};
        int dy[] = {1,0,-1};

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                for(int& x : dx) {
                    for(int& y : dy){
                        int nx = i + x, ny = j + y;
                        if(safe(nx,ny,n))
                            ans[nx - 1][ny - 1] = max(ans[nx - 1][ny - 1], grid[i][j]);
                    }
                }
            }
        }

        return ans;

    }
};