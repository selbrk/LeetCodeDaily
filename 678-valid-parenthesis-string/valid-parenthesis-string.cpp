class Solution {
public:
    bool checkValidString(string s) {
    int ctr = 0;
    int flex = 0;
    for (char &c : s) {
        if (c == '(')
            ctr++;
        if (c == ')') {
            ctr--;
            if (ctr < 0 && flex + ctr < 0)
                return false;
        }
        if (c == '*')
            flex++;
    }
    if (ctr < 0 && ctr + flex < 0)
        return false;

    if (ctr > 0 && ctr - flex > 0)
        return false;
    
    
    int open_count = (flex - ctr) / 2;
    int ctr2 = 0, star_count = 0;
    for (char &c : s) {
        if (c == '(')
            ctr2++;
        if (c == ')') {
            ctr2--;
            if (ctr2 < 0)
                return false;
        }
        if (c == '*') {
            star_count++;
            if (star_count <= open_count)
                ctr2++;
            else if ((flex - ctr) % 2 == 0) {
                if (star_count > open_count) {
                    ctr2--;
                    if (ctr2 < 0)
                        return false;
                }
            } else if ((flex - ctr) % 2 == 1) {
                if (star_count > open_count + 1) {
                    ctr2--;
                    if (ctr2 < 0)
                        return false;
                }
            }
        }
    }
    
    
    return true;
}
};