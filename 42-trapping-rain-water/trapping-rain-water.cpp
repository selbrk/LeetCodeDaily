/*
pattern -> decrease - increase

if we can get the left-most decrement block x, and right most increment block y,
height will be min(x,y) between the blocks, min(x,y) - height[i] = amount of water

*/
class Solution {
public:
    int trap(vector<int> &height) {
        int n = height.size();
        int ans = 0;

        vector<int> prefl(n, 0), prefr(n, 0);
        prefl[0] = height[0];
        for (int i = 1; i < n; i++)
            prefl[i] = max(prefl[i - 1], height[i]);
        

        prefr[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--)
            prefr[i] = max(prefr[i + 1], height[i]);
        

        for (int i = 0; i < n; i++) {
            ans += min(prefl[i], prefr[i]) - height[i];
        }

        return ans;
    }
};