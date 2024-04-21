class Solution {
public:
    vector<int> p, sz;
    
    // finds the parent of the node
    int find(int a){
        if(a == p[a]) return a;
        else return p[a] = find(p[a]);
    }


    // unites the given two components (actually nodes)
    void unite(int a, int b){
        a = find(a), b = find(b);
        if(a != b){
            // to make it somewhat balanced
            // we add the smaller tree to the 
            // bigger tree

            if(sz[b] > sz[a]) 
                swap(a, b); // swaps the pointers
            
            
            p[b] = a;
            sz[a] += sz[b];
        }
    }


    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(source == destination)
            return true;
        
        p.resize(n);
        sz.resize(n);

        for(int i = 0; i < n; i++){
            p[i] = i; // with all nodes being single, initially their parents are themselves
            sz[i] = 1; // and the subtree is sized 1.
        }

        for(auto& edge : edges)
            unite(edge[0], edge[1]);
        
        return find(source) == find(destination);
        

        
    }
};