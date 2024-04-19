class Solution {
public:
    int numSub(string s) {
        const int mod = 1e9 + 7;
        int ans = 0, one_counter = 0;
        for(char& c : s)
            if(c == '1')
                (ans += ++one_counter) %= mod;
            else 
                one_counter = 0;
        return ans;
    }
};