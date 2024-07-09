class Solution {
public:
    int countSpecialSubsequences(vector<int>& nums) {
        int n = nums.size();
        int mod = 1e9 + 7;
        vector<vector<int>> dp(n + 1, vector<int>(3));

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                dp[i + 1][0] = (2 * dp[i][0] + 1) % mod;
                dp[i + 1][1] = dp[i][1];
                dp[i + 1][2] = dp[i][2];
            } else if (nums[i] == 1) {
                dp[i + 1][0] = dp[i][0];
                dp[i + 1][1] = ((2 * dp[i][1]) % mod + dp[i][0]) % mod;
                dp[i + 1][2] = dp[i][2];
            } else {
                dp[i + 1][0] = dp[i][0];
                dp[i + 1][1] = dp[i][1];
                dp[i + 1][2] = ((2 * dp[i][2]) % mod + dp[i][1]) % mod;
            }
        }
        return dp[n][2];
    }
};