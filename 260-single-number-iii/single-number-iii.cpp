class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int no1 = 0, no2 = 0, allxor = 0, onebit;

        for(int& x : nums) 
            allxor ^= x;

        // find a bit that allxor has
        for(int i = 0; i < 30; i++) 
            if((1<<i) & allxor)
                onebit = i;
        
        for(int& x : nums)
            if((1 << onebit) & x)
                no1 ^= x;
            else
                no2 ^= x;
        

        return {no1, no2};

        

    }
};