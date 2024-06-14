class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int last_element = nums[0], ans = 0;

        for(int i = 1; i < nums.size(); i++)
            if(nums[i] <= last_element)
                ans += ++last_element - nums[i];
            else
                last_element = nums[i];
        return ans;
    }
};