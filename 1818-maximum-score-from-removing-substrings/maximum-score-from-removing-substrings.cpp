class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int ans = 0;
        stack<char> st;

        for(char& c : s) {
            if(st.empty()) st.push(c);
            else if(y < x && c == 'b' && st.top() == 'a') ans += x, st.pop();
            else if(y >= x && c == 'a' && st.top() == 'b') ans += y, st.pop();
            else st.push(c);
        }
        
        stack<char> st2;
        while(!st.empty()) {
            char c = st.top(); st.pop();
            if(st2.empty()) st2.push(c);
            else if(y < x && c == 'b' && st2.top() == 'a') ans += y, st2.pop();
            else if(y >= x && c == 'a' && st2.top() == 'b') ans += x, st2.pop();
            else st2.push(c);
        }
        while(!st.empty()) cout << st.top() << " ", st.pop();
        /*
        b -> 0
        bbaaabab -> a : 4, b : 4 -> max olması için y > x ise önce atabileceğimiz b'leri saymamız gerek.
        b
        bb
        bba attık b -> 1 a -> 0 y
        bbaa attık b -> 0 a -> 0 y
        bbaaa b -> 0 a -> 1
        bbaaab b -> 1 a-> 0
        */
        return ans;
    }
};