class Solution {
public:
    string convertToBase7(int num) {
        if(num == 0)
            return "0";
        bool pos = (num >= 0);
        string ans = "";
        num = abs(num);
        while(num) {
            ans = to_string(num % 7) + ans;
            num /= 7;
        }
        if (!pos)
            ans = "-" + ans;
        
        return ans;

    }
};