vector<int>topoSort(int V,vector<int>adj[]){
        vector<int> indegree(V,0);
	    
	    for(int i=0;i<V;i++)
	        for(auto it:adj[i])
	            indegree[it]++;
	        
	   vector<int> toposort;
	   queue<int>q;
	   
	   for(int i=0;i<V;i++)
	     if(indegree[i]==0) 
	       q.push(i);
	     
	   while(!q.empty()){
	       int node = q.front();
	       q.pop();
	       toposort.push_back(node);
	       for(auto it:adj[node]){
	           indegree[it]--;
	           if(indegree[it]==0)
	             q.push(it);
	       }
	   }
	   return toposort;
    }
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    vector<int> adj[N];
	    for(auto it:prerequisites)
	        adj[it.second].push_back(it.first);
	    return topoSort(N,adj).size()==N;
	}