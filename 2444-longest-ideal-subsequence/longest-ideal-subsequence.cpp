class Solution {
public:
    int longestIdealString(string s, int k) {


    int n = s.size(), ans = 1;
    vector<int> lastSeen(26, -1), dp(n, 1);
    lastSeen[s[0] - 'a'] = 0;


    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 26; j++) {
            if (abs((s[i] - 'a') - j) <= k && lastSeen[j] != -1) {
                dp[i] = max(dp[i], dp[lastSeen[j]] + 1);
            }
        }
        ans = max(ans, dp[i]);
        lastSeen[s[i] - 'a'] = i;
    }

    return ans;
}
};