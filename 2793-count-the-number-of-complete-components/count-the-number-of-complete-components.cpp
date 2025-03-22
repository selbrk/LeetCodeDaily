class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        vector<bool> vis(n);
        int ans = 0;

        auto bfs = [&](int root){
            if (vis[root])
                return false;

            int deg = adj[root].size();
            queue<int> q;
            q.push(root);
            int node_cnt = 1;
            bool ok = true;

            while (!q.empty()) {
                int v = q.front();
                q.pop();
                vis[v] = true;
                if (adj[v].size() != deg) ok = false;

                for (int& nbr : adj[v]) {
                    if (!vis[nbr]) {
                        q.push(nbr);
                        vis[nbr] = true;
                        node_cnt++;
                    }
                }
            }

            return ok && (node_cnt == (deg + 1));
        };

        for (int i = 0; i < n; i++)
            ans += bfs(i);
        return ans;
    }
};