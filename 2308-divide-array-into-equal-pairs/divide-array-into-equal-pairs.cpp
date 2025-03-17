class Solution {
public:
    bool divideArray(vector<int>& nums) {
        vector<bool> ok(501, true);


        for (int& num : nums)
            ok[num] = !ok[num];
        
        bool ans = true;

        for(bool b : ok)
            ans &= b;
        
        return ans;
        


    }
};