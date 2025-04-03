class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n);
        dp[n - 1] = questions[n - 1][0];
        for (int i = n - 2; i >= 0; i--)
            if (i + questions[i][1] + 1 >= n)
                dp[i] = max(dp[i + 1], 1ll * questions[i][0]);
            else
                dp[i] = max(dp[i + 1], 1ll * questions[i][0] + dp[i + questions[i][1] + 1]);
        return dp[0];
    }
};