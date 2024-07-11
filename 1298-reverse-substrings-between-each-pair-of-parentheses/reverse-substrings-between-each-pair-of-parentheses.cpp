class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        string ans = "";
        for(char& c : s) {
            if(c == ')') {
                string temp = "";
                while(st.top() != '(') {
                    char rm = st.top(); st.pop();
                    temp += rm;
                }
                st.pop();
                for(char& d : temp) {
                    st.push(d);
                }
            } else {
                st.push(c);
            }
        }

        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());


        return ans;
    }
};