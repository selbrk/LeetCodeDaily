class Solution {
public:
    string reversePrefix(string word, char ch) {
        bool found = false;
        vector<char> letters;
        string ans = "";
        for (char c : word) {
            if (c == ch && !found) {
                found = true;
                letters.push_back(c);
                for (int i = letters.size() - 1; i >= 0; i--) {
                    ans += letters[i];
                }
            } else if (found) {
                ans += c;
            } else if (!found) {
                letters.push_back(c);
            }
        }

        if (!found)
            return word;
        return ans;
    }
};