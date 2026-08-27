class Solution {
  public:
    int countEdges(vector<vector<int>>& adj) {
        // code here
        int n = adj.size();
        int totalindegree = 0;
        for(int i = 0 ; i<n ; i++){
            totalindegree+=adj[i].size();
        }
        int edgescount = totalindegree/2;
        return edgescount;
    }
};