class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        // binary search for the answer

        int l = 1, r = *max_element(nums.begin(), nums.end());
        int ans = r;


        auto ok = [&](int c) {
            int took = 0;
            int i = 0;

            for(int i = 0; i < nums.size(); i++) {
                if(nums[i] <= c)
                    took++,i++;
            }
            return took >= k;
        };

        while (l <= r) {
            int mid = l + (r-l) / 2;
            if (ok(mid)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid+1;
            }
        }

        return ans;
    }
};