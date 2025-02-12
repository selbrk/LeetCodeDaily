class Solution {
public:

    int sum_of_digits(int num) {
        int sum = 0;
        while (num) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        vector<priority_queue<int>> groups(82);
        for(int i = 0; i < nums.size(); i++) {
            int digitsum = sum_of_digits(nums[i]);
            groups[digitsum].push(nums[i]);
        }
        int ans = -1;
        for(int i = 1; i <= 81; i++) {
            if (groups[i].size() < 2) continue;
            int f = groups[i].top(); groups[i].pop();
            int s = groups[i].top();
            ans = max(ans, f + s);
        }
        return ans;
    }
};