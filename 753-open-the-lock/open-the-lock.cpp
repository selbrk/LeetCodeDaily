class Solution {
public:
    vector<vector<int>> findNeighbors(vector<int>& curr) {
        vector<vector<int>> ans;
        vector<int> copyv;
        for(int i = 0; i < 4; i++) {
            copyv = curr;
            copyv[i]++;
            copyv[i] %= 10;
            ans.push_back(copyv);
        }
        for(int i = 0; i < 4; i++) {
            copyv = curr;
            copyv[i]+=9;
            copyv[i] %= 10;
            ans.push_back(copyv);
        }
        return ans;
    }

    int toInt(vector<int>& curr) {
        int ans = 0;
        for(int i = 0; i < 4; i++) {
            ans *= 10;
            ans += curr[i];
        }
        return ans;
    }

    int openLock(vector<string>& deadends, string target) {
        int n = deadends.size();

        vector<vector<int>> deadendsInt(n, vector<int>(4));
        unordered_map<int,bool> vis;
        for(int j = 0; j < n; j++)
            for(int i = 0; i < 4; i++)
                deadendsInt[j][i] = deadends[j][i] - '0';
        
        queue<pair<int,vector<int>>> q;
        q.push({0, {0,0,0,0}});
        vector<int> targetArray = {target[0] - '0', target[1] - '0', target[2] -'0', target[3] - '0'};

        unordered_set<int> forbidden;

        for(vector<int>& x : deadendsInt)
            forbidden.insert(toInt(x));
        

        
        while(!q.empty()) {
            int level = q.front().first;
            vector<int> current = q.front().second;
            vis[toInt(current)] = true;

            q.pop();

            if(current == targetArray)
                return level;
            
            if(forbidden.count(toInt(current)))
                continue;
            
            vector<vector<int>> ngbrs = findNeighbors(current);

            for(vector<int>& ngbr : ngbrs)
                if(!vis[toInt(ngbr)])
                    {vis[toInt(ngbr)] = true; q.emplace(level+1, ngbr);}
            
        }
        return -1;
    }
};