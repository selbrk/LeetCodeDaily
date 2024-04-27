class Solution {
public:
    int calculate(int i, int j, int mod) {
        if(j > i) {
            return min(j - i, i + mod - j);
        } else {
            return min(i-j, j + mod - i);
        }
    }
    int findRotateSteps(string ring, string key) {
    int spell = key.size(), mod = ring.size();
    // dp[i][j] -> minimum cost on i th index when it is on j th index of the ring.
    vector<vector<int>> dp(spell, vector<int>(mod, INT_MAX)), ind(26);

    for (int i = 0; i < mod; i++) {
        ind[ring[i] - 'a'].push_back(i);
    }

    for (int i = 0; i < spell; i++) {
        for (int j = 0; j < mod; j++) {
            if (key[i] == ring[j]) {
                if (i == 0) {
                    dp[i][j] = min(j, mod - j) + 1;
                } else {
                    for (int k : ind[key[i - 1] - 'a']) {
                        if (dp[i - 1][k] != INT_MAX) {
                            dp[i][j] = min(dp[i][j], dp[i - 1][k] + min(calculate(j, k, mod), calculate(k, j, mod)) + 1);
                        }
                    }
                }
            }
        }
    }

    return *min_element(dp[spell - 1].begin(), dp[spell - 1].end());
}
};