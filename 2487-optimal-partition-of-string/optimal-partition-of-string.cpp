class Solution {
public:
    int partitionString(string s) {
        int ans = 1;
        set<int> seen; // 0->a, 1->b, ..., 26->z
        for(char& c : s) {
            int cur_letter = c - 'a';
            if(seen.count(cur_letter)) {
                ans++;
                seen.clear();
            } 
            seen.insert(cur_letter);
        }
        return ans;
    }
};