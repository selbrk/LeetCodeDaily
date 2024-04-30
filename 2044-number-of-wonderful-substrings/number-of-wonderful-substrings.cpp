class Solution {
public:
    long long wonderfulSubstrings(string word) {
        unordered_map<int,int> mp;
        mp[0] = 1;
        long long res = 0;
        int mask = 0;

        for(char ch : word) {
            int ix = ch - 'a';
            mask ^= (1 << ix);
            res += mp[mask];
            for(int i = 0; i < 10; i++) {
                res += mp[mask ^ (1 << i)];
            }
            mp[mask]++;
        }

        return res;
    }

        
};