class Solution {
public:
    vector<int> count, down_roads, ans;
    void dfs1(int root, int parent, vector<vector<int>>& adj) {
        for (int& nbr : adj[root]) {
            if (nbr != parent) {
                dfs1(nbr, root, adj);
                count[root] += count[nbr];
            }
        }
    }

    void dfs2(int root, int parent, vector<vector<int>>& adj) {
        for (int& nbr : adj[root]) {
            if (nbr != parent) {
                dfs2(nbr, root, adj);
                down_roads[root] += down_roads[nbr] + count[nbr];
            }
        }
    }

    void dfs3(int root, int parent, vector<vector<int>>& adj, int n) {
        ans[root] += down_roads[root];
        if (parent != -1) {
            int rem = ans[parent] - ans[root] - count[root];
            int rem_nodes = n - count[root];
            ans[root] += rem + rem_nodes;
        }
        for (int& nbr : adj[root]) {
            if (nbr != parent)
                dfs3(nbr, root, adj, n);
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        int u, v;
        for (auto& edge : edges) {
            u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        count.resize(n, 1);
        down_roads.resize(n, 0);
        ans.resize(n, 0);

        dfs1(0, -1, adj);
        dfs2(0, -1, adj);
        dfs3(0, -1, adj, n);

        return ans;
    }
};