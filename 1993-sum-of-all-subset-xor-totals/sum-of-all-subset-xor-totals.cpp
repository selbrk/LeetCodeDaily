class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();

        int ans = 0;
        for (int i = 0; i < (1 << n); i++) {
            int xor_of_subset= 0;
            for(int j = 0; j < n; j++) 
                if ((1 << j) & i)
                    xor_of_subset ^= nums[j];
            ans += xor_of_subset;
        }

        return ans;


    }
};