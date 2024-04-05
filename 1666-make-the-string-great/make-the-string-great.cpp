class Solution {
public:

    string makeGood(string s) {
        stack<char> letters; 
        for(char& c: s) {
            // if the last character matches, delete the last character.
            if(!letters.empty() && abs(c - letters.top()) == 32) letters.pop();
            // else add the letter
            else letters.push(c);
        }
        string ans = "";
        // concatenate the letters
        while(!letters.empty()) {
            ans = letters.top() + ans;
            letters.pop();
        }

        return ans;
    }
    
};