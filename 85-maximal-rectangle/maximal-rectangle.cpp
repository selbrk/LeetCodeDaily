/*

let dp[rows][cols][cols] be a matrix where dp[i][j][k] = maximum rectangle that's right bottom 
corner is (i,j) and it's width is k. so obviously, if k > j dp[i][j][k] = 0.

how to formulate dp[i][j][k]? first of all, if matrix[i][j] = '0', then it is 0.

else, dp[i][j][k] = dp[i][j-1][k-1] + dp[i-1][j][k] - dp[i-1][j-1][k-1] + 1


*/

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size(), ans = 0;
        vector<int> hist(cols + 1);
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++)
                hist[j] =  (matrix[i][j] == '1') ? hist[j] + 1 : 0;
            
            stack<int> st;
            for (int j = 0; j < hist.size(); j++) {
                while (!st.empty() && hist[j] < hist[st.top()]) {
                    int h = hist[st.top()];
                    st.pop();
                    int w = st.empty() ? j : j - st.top() - 1;
                    ans = max(ans, h * w);
                }
                st.push(j);
            }

        }
        return ans;
    }
};