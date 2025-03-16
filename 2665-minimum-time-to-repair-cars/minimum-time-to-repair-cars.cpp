class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        // binary search to the answer?
        // checking if m minutes is enough:
        // m = r * n^2 with max n.
        // n = floor(sqrt(m / r))
        // sigma n >= cars ? ok : not

        // time complexity of this solution is (N* log (LLONG_MAX))


        long long ans = LLONG_MAX;

        long long lo = 0, hi = LLONG_MAX;
        long long mid;

        auto check = [&](long long m) {
            long long n, total = 0;
            for (int& r : ranks) {
                n = sqrt((double)(m) / r);
                total += n;
            }

            return (total >= cars) ? true : false;
        };
        
        while (lo <= hi) {
            mid = lo + (hi - lo) / 2;
            if (check(mid))
                ans = mid, hi = mid - 1;
            else 
                lo = mid + 1;
        }

        return ans;





    }
};