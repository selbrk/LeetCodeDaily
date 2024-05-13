class Solution {
public:
    void flipRow(int i, vector<vector<int>>& grid) {
        int m = grid[i].size();
        for(int j = 0; j < m; j++){
            grid[i][j] = 1 - grid[i][j];
        }
    }


    void flipColumn(int j, vector<vector<int>>& grid) {
        int n = grid.size();
        for(int i = 0; i < n; i++) {
            grid[i][j] = 1 - grid[i][j];
        }
    }

    int matrixScore(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), ans = 0;

        for(int i = 0; i < n; i++)
            if(grid[i][0] == 0)
                flipRow(i, grid);
            

        for(int j = 1; j < m; j++) {
            int one_ctr = 0;
            for(int i = 0; i < n; i++)
                if(grid[i][j] == 1)
                    one_ctr++;
            
            if(2*one_ctr < n)
                flipColumn(j, grid);
        }

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(grid[i][j]) 
                    ans += (1 << (m-j-1));
            

        return ans;

    }
};