class Solution {
public:
    int countSpecialSubsequences(vector<int>& nums) {
        int n = nums.size();
        int mod = 1e9 + 7;
        int a = 0, b = 0, c = 0;

        for (int i = 0; i < n; i++)
            if (nums[i] == 0)
                a = (2 * a + 1) % mod;
            else if (nums[i] == 1)
                b = ((2 * b % mod) + a) % mod;
            else
                c = ((2 * c % mod) + b) % mod;

        return c;
    }
};