class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size(), n = grid[0].size();
        vector<int> flat(m*n);
        for(int i = 0; i < m; i++) 
            for(int j = 0; j < n; j++)
                flat[i*n+j] = grid[i][j];
        
        sort(flat.begin(), flat.end());
        int r = flat[0] % x;
        for(int i = 0; i < m*n; i++)
            if (flat[i] % x != r)
                return -1;
        int median = flat[m*n/2];
        int ops=0;
        for(int i = 0; i < m*n; i++)
            ops += abs(flat[i] - median) / x;
        return ops;
    }
};