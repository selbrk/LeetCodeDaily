class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int ans = 0;
        stack<char> st, st2;

        for (char& c : s)
            if (st.empty())
                st.push(c);
            else if (y < x && c == 'b' && st.top() == 'a')
                ans += x, st.pop();
            else if (y >= x && c == 'a' && st.top() == 'b')
                ans += y, st.pop();
            else
                st.push(c);

        while (!st.empty()) {
            char c = st.top();
            st.pop();
            if (st2.empty())
                st2.push(c);
            else if (y < x && c == 'b' && st2.top() == 'a')
                ans += y, st2.pop();
            else if (y >= x && c == 'a' && st2.top() == 'b')
                ans += x, st2.pop();
            else
                st2.push(c);
        }

        return ans;
    }
};