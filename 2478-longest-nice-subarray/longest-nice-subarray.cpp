class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int l = 0, r = 0, ans=1, mask = 0, n = nums.size();
        while (r < n) {
            if (nums[r] & mask)
                mask ^= nums[l++];
            else
                mask |= nums[r++];
            ans = max(ans, r-l);
        }
        return ans;
    }
};