class Solution {
  public:
    bool checkEdge(vector<vector<int>>& adj, int u, int v) {
        
        // code here
        
        for(int i = 0 ; i<adj.size() ; i++){
            for(int j = 0 ; j<adj[i].size() ; j++){
                if(i==u && adj[i][j]==v || i==v && adj[i][j]==u) return true;
            }
            
        }
        
        return false;
    }
};