class Solution {
public:
    int minOperations(vector<string>& logs) {
        int ans = 0;
        for (string& s : logs)
            if (s == "./")
                continue;
            else if (s == "../")
                ans = max(ans - 1, 0);
            else
                ans++;
        return ans;
    }
};