class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        sort(nums.begin(),nums.end());
        int ans = 1, ctr = 1, last = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] == last) continue;
            if(nums[i] == last + 1)
                ans = max(ans,++ctr);
            else
                ctr = 1;
            last = nums[i];
        }

        return ans;
    }
};