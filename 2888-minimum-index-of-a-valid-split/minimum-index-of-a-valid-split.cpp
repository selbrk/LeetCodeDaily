class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size(), count = 1, dominant = nums[0];

        for (int i = 1; i < n; i++) {
            if (nums[i]==dominant)
                count++;
            else if (count > 0)
                count--;
            else 
                count = 1, dominant = nums[i];
        }

        int dominant_count = 0;
        for (int& num : nums)
            if (num == dominant)
                dominant_count++;
        
        int cur_count = 0;

        auto valid = [&] (int i) {
            // cur_count > (i + 1) / 2 && dominant_count - cur_count > n-i+1 / 2
            cur_count += nums[i] == dominant;
            return cur_count > (i + 1) / 2 && dominant_count - cur_count > (n - i - 1) / 2;
        };
        
        for (int i = 0; i < n; i++)
            if (valid(i))
                return i;
        

        return -1;
    }
};