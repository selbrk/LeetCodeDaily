class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int l, r, sum;
        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i-1])
                continue;
            l = i + 1;
            r = n - 1;
            while (l < r) {
                sum = nums[i] + nums[l] + nums [r];
                if (sum > 0)
                    r--;
                else if (sum < 0)
                    l++;
                else {
                    ans.push_back({nums[i],nums[l],nums[r]});
                    l++;
                    while (l < r && nums[l] == nums[l-1]) 
                        l++;
                }
            }
        }
        return ans;
    }
};