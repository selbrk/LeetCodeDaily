class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        
        deque<pair<int, int>> dq;
        int n = nums.size();
        if(n == 1)
            return nums[0];

        dq.push_back({nums[0], 0});
        for (int i = 1; i < n; i++) {

            while (dq.size() && i > dq.front().second + k) {
                dq.pop_front();
            }

            int new_value = nums[i] + dq.front().first;

            if (i == n - 1) {
                return new_value;
            }

            pair<int, int> new_pair = {new_value, i};

            while (dq.size() && dq.back().first <= new_value) {
                dq.pop_back();
            }

            dq.push_back(new_pair);
        }
        return 0;
    }
};