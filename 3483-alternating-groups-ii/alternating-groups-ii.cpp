class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        for(int i = 0; i < k - 1; i++)
            colors.push_back(colors[i]);
        vector<int> dp(colors.size(), 1); // dp[i] = maximum length of alternating sequence ending at index i

        for (int i = 1; i < colors.size(); i++) 
            dp[i] = (colors[i] != colors[i-1]) ? dp[i-1] + 1: 1;
        
        int ans = 0;

        for (int i = 0; i < dp.size(); i++)
            if (dp[i] >= k)
                ans++;
        
        return ans;
        

    }
};