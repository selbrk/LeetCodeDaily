class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> ans;
        
        int m = land.size(), n = land[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(vis[i][j] || land[i][j] == 0) continue;
                int leftX = i, leftY = j;
                while(leftX + 1 < m && land[leftX+1][j]) leftX++;
                while(leftY + 1 < n && land[i][leftY+1]) leftY++;
                ans.push_back({i,j,leftX,leftY});
                for(int k = i; k <= leftX; k++)
                    for(int l = j; l <=leftY; l++)
                        vis[k][l] = true;
            }
        }
        return ans;
    }
};