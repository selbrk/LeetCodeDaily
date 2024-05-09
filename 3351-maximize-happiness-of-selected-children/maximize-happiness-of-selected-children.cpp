class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long ans = 0;
        sort(happiness.begin(),happiness.end());
        int n = happiness.size();
        for(int i = 0; i < k; i++) {
            ans += max(happiness[n-i-1] - i, 0);
        }
        return ans;
    }
};