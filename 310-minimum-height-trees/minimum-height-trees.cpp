class Solution {
public:
    
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) return {0};
        vector<int> ans;

        queue<int> leaves;

        vector<int> adj[n];

        vector<int> deg(n);

        int u, v, total_node = n;
        for(auto& edge : edges) {
            u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            deg[u]++;
            deg[v]++;
        }

        for(int i = 0; i < n; i++)
            if(deg[i] == 1)
                leaves.push(i);
        
        while(total_node > 2) {
            int k = leaves.size();
            for(int i = 0; i < k; i++) {
                int leaf = leaves.front(); leaves.pop(); total_node--;
                for(int& nbr : adj[leaf]) {
                    deg[nbr]--;
                    if(deg[nbr] == 1)
                        leaves.push(nbr);
                }
            }
        }

        while(!leaves.empty()) {
            ans.push_back(leaves.front()); leaves.pop();
        }

        return ans;
        

        

    }
};