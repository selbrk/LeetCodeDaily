class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string ans = "";
        
        stack<pair<char,int>> st;
        unordered_set<int> to_erase;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(') st.push({s[i], i});
            else if(s[i] == ')' && !st.empty() && st.top().first == '(') st.pop();
            else if(s[i] == ')') to_erase.insert(i); 
        }
        
        while(!st.empty()) {
            to_erase.insert(st.top().second);
            st.pop();
        }
        for(int i = 0; i< s.size(); i++) {
            if(to_erase.count(i)) continue;
            ans += s[i];
        }

        return ans;
    }
};