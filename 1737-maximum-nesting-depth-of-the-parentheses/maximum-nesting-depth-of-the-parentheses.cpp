class Solution {
public:
    int maxDepth(string s) {
        int open_bracket_count = 0; 
        int ans = 0;
        for(char &c : s) {
            if(c == '(') {
                open_bracket_count++;
                ans = max(ans, open_bracket_count);
            }
            else if(c == ')')
                open_bracket_count--;
        }

        return ans;
    }
};