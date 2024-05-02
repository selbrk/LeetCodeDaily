class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int ans = -1;

        unordered_set<int> s;

        for(int& num : nums) {
            s.insert(num);
            if(s.count(-num))
                ans = max(abs(num), ans);
        }

        return ans;
    }
};