class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(source == destination)
            return true;
        

        vector<int> adj[n];
        vector<bool> vis(n, false);
        int u, v;
        for(int i = 0; i < edges.size(); i++) {
            u = edges[i][0], v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        queue<int> bfs;
        bfs.push(source);
        vis[source] = true;
        int node;
        while(!bfs.empty()) {
            node = bfs.front();
            bfs.pop();

            for(int& nbr : adj[node]) {    
                if(!vis[nbr]){
                    vis[nbr] = true;
                    bfs.push(nbr);
                    if(nbr == destination)
                        return true;
                }
            }
        }

        return false;

        
    }
};