class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ans = 0;

        vector<int> bit_count(31,0); // counts bits modulo 2

        for(int i = 0; i < 31; i++)
            for(int& num : nums)
                if(num & (1 << i))
                    bit_count[i]++;
        
        for(int i = 0; i < 31; i++) {
            int get_bit = (k & (1 << i)) ? 1 : 0;
            int total_bit = bit_count[i] % 2;
            ans +=  (get_bit-total_bit + 2) % 2;
        }

        return ans;

            

        // k -> 0000001
    }
};