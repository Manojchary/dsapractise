class Solution {
  public:
     
    int shortestPath(vector<vector<int>> &mat) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        if(m==1){
            int there = -1;
            for(int j = 0 ; j<n ; j++){
                if(mat[0][j]==1){
                    there = 0;
                }
            }
            return there;
        }
        
        vector<vector<int>>safe(n , vector<int>(m , -1));
        
        vector<int>drow = {-1 , 0 , 1 , 0};
        vector<int>dcol = {0 , 1 , 0 , -1};
        for(int i = 0 ; i<n ; i++){
            for(int j = 0 ; j<m ; j++){
                if(mat[i][j]==0) {
                    safe[i][j] = 0;
                    for(int k = 0 ; k<4 ; k++){
                        int nrow = i+drow[k];
                        int ncol = j+dcol[k];
                        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                           safe[nrow][ncol] = 0;
                        }
                    }
                }
            }
        }
        // Multi-source BFS
        queue<pair<int,int>> q;

        // Every safe cell in the leftmost column is a source
        for(int i = 0; i < n; i++) {

            if(safe[i][0] == -1) {

                q.push({i, 0});
                safe[i][0] = 0;   // mark visited
            }
        }
        int steps = 1;

        while(!q.empty()) {

            int size = q.size();

            while(size--) {

                auto [r, c] = q.front();
                q.pop();

                // Reached rightmost column
                if(c == m - 1)
                    return steps;

                for(int k = 0; k < 4; k++) {

                    int nr = r + drow[k];
                    int nc = c + dcol[k];

                    if(nr >= 0 && nr < n &&
                       nc >= 0 && nc < m &&
                       safe[nr][nc] == -1) {

                        safe[nr][nc] = 0;
                        q.push({nr, nc});
                    }
                }
            }

            steps++;
        }

        return -1;
        
    }
};
