class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int l = 1, r = 10000000;

        int ans = 0;

        auto ok = [&](int c) {
            long long total = 0;

            for(int i = 0; i < candies.size(); i++) {
                total += (candies[i] / c);
            }

            return total >= k;
        };


        while (l <= r) {
            int mid = l + (r-l) / 2;

            if(ok(mid))
                ans = mid, l = mid + 1;
            else 
                r = mid - 1;
        }


        return ans;


    }
};