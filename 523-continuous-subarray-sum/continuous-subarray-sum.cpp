class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> seen;
        int last_seen_value = 0;
        int prefix_sum = 0;
        seen[0] = 1;

        for(int i = 0; i < nums.size(); i++) {
            prefix_sum += nums[i];
            prefix_sum %= k;
            if(seen[prefix_sum] > 1)
                return true;
            else if(seen[prefix_sum] == 1 && last_seen_value != prefix_sum)
                return true;
            
            seen[prefix_sum]++;
            last_seen_value = prefix_sum;
        }


        return false;
    }
};