class Solution {
  public:
    bool isNegativeWeightCycle(int V, vector<vector<int>>& edges) {
        // code here
        vector<int>dis(V , 1e9);
        dis[0] = 0;
        // v-1 times 
        for(int i = 1 ; i<=V-1 ; i++){
            for(int e = 0 ; e<edges.size() ; e++){
                int u = edges[e][0];
                int v = edges[e][1];
                int w = edges[e][2];
                if(dis[u]!=1e9 && dis[u]+w<dis[v]){
                    dis[v] = dis[u]+w;
                }
                
            }
        }
        for(int e = 0 ; e<edges.size() ; e++){
            int u = edges[e][0];
            int v = edges[e][1];
            int w = edges[e][2];
            if(dis[u]!=1e9 && dis[u]+w<dis[v]){
                return true;
            }
            
        }
        return false;
        
    }
};