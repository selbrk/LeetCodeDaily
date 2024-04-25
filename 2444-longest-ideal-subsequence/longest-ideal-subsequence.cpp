class Solution {
public:
    int longestIdealString(string s, int k) {


    int n = s.size();
    vector<int> lastSeen(26, -1), dp(n, 1);
    lastSeen[s[0] - 'a'] = 0;

    
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 26; j++) {
            if (abs((s[i] - 'a') - j) <= k && lastSeen[j] != -1) {
                dp[i] = max(dp[i], dp[lastSeen[j]] + 1);
            }
        }
        lastSeen[s[i] - 'a'] = i;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, dp[i]);
        cout << dp[i] << " ";
    }

    return ans;
}
};