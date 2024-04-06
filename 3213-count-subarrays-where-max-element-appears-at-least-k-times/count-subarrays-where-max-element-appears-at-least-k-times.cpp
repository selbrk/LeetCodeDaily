class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size(); // number of elements in the array
        long long ans = 0; // answer
        int val = *max_element(nums.begin(),nums.end()); // maximum value in the array
        vector<int> pref(n+1); // counts the occurences of maximum value 

        for(int i = 1; i<=n; i++) {
            if(nums[i-1] == val) 
                pref[i] = pref[i-1] + 1;
            else 
                pref[i] = pref[i-1];
        }

        for(int i = 1; i<=n; i++) {
            if(pref[i] < k) continue;
            
            int target = pref[i] - k;
            int ix = upper_bound(pref.begin(), pref.end(), target) - pref.begin();
            ans += ix;
        }
        return ans;


    }
};