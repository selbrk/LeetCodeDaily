class Solution {
public:
    int numberOfSubstrings(string s) {
        int count[3] = {0,0,0}, res=0,start=0;
        auto ok = [&]() {return count[0] && count[1] && count[2];};
        for(int end = 0; end < s.size(); end++) {
            count[s[end]-'a']++;
            while(ok())
                count[s[start++]-'a']--;
            res += start;
        }
        return res;
    }
};