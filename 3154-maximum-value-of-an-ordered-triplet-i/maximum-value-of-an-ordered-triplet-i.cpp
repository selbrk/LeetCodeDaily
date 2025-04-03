class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long ans = 0;
        int max_diff = 0;
        int cur_max = nums[0];
        for (int i = 1; i < nums.size(); i++)
            ans = max(ans, max_diff * 1ll * nums[i]), max_diff = max(max_diff, cur_max - nums[i]), cur_max = max(cur_max, nums[i]);
        return ans;
    }
};