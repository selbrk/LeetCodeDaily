class Solution {
public:
    
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) return {0};
        vector<int> ans;

        queue<int> leaves;

        vector<int> adj[n];

        vector<int> deg(n);

        int u, v, k, leaf;
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
        
        while(n > 2) {
            k = leaves.size();
            for(int i = 0; i < k; i++) {
                leaf = leaves.front(); leaves.pop(); n--;
                for(int& nbr : adj[leaf]) {
                    if(--deg[nbr] == 1)
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