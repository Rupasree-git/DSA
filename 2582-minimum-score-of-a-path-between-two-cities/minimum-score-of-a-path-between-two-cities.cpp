class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n+1);
        
        // Build graph
        for(auto &r : roads){
            adj[r[0]].push_back({r[1], r[2]});
            adj[r[1]].push_back({r[0], r[2]});
        }
        
        vector<bool> vis(n+1, false);
        queue<int> q;
        
        q.push(1);
        vis[1] = true;
        
        int ans = INT_MAX;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(auto &it : adj[node]){
                int neigh = it.first;
                int dist = it.second;
                
                ans = min(ans, dist);  // track minimum edge
                
                if(!vis[neigh]){
                    vis[neigh] = true;
                    q.push(neigh);
                }
            }
        }
        
        return ans;
    }
};