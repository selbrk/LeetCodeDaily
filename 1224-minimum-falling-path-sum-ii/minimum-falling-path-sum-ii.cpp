class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dp(n,vector<int>(n));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                dp[i][j] = grid[i][j];
            }
        }
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < n; j++) {
                int minRow = INT_MAX;
                for(int k = 0; k < n; k++) {
                    if(k != j) {
                        minRow = min(minRow, dp[i-1][k]);
                    }
                }
                dp[i][j] += minRow;
            }
        }
        int ans = INT_MAX;
        for(int i = 0; i < n; i++)
            ans = min(ans,dp[n-1][i]);
        return ans;
        
    }
};