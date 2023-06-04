bool dfs(int node,vector<int>&vis,vector<int>&pathvis,
    vector<int>adj[]){
        vis[node] = 1;
        pathvis[node] = 1;
        for(auto it:adj[node]){
            if(!vis[it]){
                if(dfs(it,vis,pathvis,adj)) return 1;
            }
            else if(pathvis[it]) return 1;
        }
        pathvis[node] = 0;
        return 0;
    }
    bool isCyclic(int V, vector<int>adj[]) {
        vector<int>vis(V,0),pathvis(V,0);
        for(int i=0;i<V;i++)
            if(!vis[i])
                if(dfs(i,vis,pathvis,adj)) return 1;
        return 0;
    }