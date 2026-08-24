class Solution {
public:
    int numberOfCells(int r, int c, int u, int d, vector<vector<char>> &mat) {

        if(mat[r][c] == '#') return 0;

        int n = mat.size();
        int m = mat[0].size();

        queue<pair<pair<int,int>, pair<int,int>>> q;

        // Instead of bool visited
        // store maximum remaining U
        vector<vector<int>> vis(n, vector<int>(m, -1));

        q.push({{r, c}, {u, d}});
        vis[r][c] = u;

        int res = 1;

        vector<int> drow = {-1, 0, 1, 0};
        vector<int> dcol = {0, 1, 0, -1};

        while(!q.empty()) {

            auto p = q.front();
            q.pop();

            int row = p.first.first;
            int col = p.first.second;

            int ucount = p.second.first;
            int dcount = p.second.second;

            for(int i = 0; i < 4; i++) {

                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                int newU = ucount;
                int newD = dcount;

                if(nrow < row)
                    newU--;

                if(nrow > row)
                    newD--;

                if(newU >= 0 &&
                   newD >= 0 &&
                   nrow >= 0 &&
                   nrow < n &&
                   ncol >= 0 &&
                   ncol < m &&
                   mat[nrow][ncol] == '.' &&
                   vis[nrow][ncol] < newU) {

                    // If we reach this cell with more U remaining,
                    // this is a better state.
                    if(vis[nrow][ncol] == -1)
                        res++;

                    vis[nrow][ncol] = newU;

                    q.push({{nrow, ncol}, {newU, newD}});
                }
            }
        }

        return res;
    }
};