class Solution {
  public:
    vector<vector<int>> findInOutDegree(int V, vector<vector<int>>& edges) {
        // code here
        vector<int>indegree(V);
        vector<int>outdegree(V);
        for(int i = 0 ; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            //u->v 
            indegree[v]++;
            outdegree[u]++;
        }
        vector<vector<int>>res;
        for(int i = 0 ; i<V ; i++){
            res.push_back({indegree[i] , outdegree[i]});
        }
        
        return res;
    }
};