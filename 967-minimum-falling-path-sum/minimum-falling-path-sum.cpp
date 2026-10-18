class Solution {
public:
    int solve(int i , int j , int n , int m , vector<vector<int>>&matrix , vector<vector<int>>&dp ){
        // base case
        if(j>=m || j<0 ) return INT_MAX;

        if(i==n-1) return matrix[i][j];

        if(dp[i][j]!=-1) return dp[i][j];

        int pres = matrix[i][j];
        int leftdown = INT_MAX;

        int down = pres+solve(i+1 , j , n , m , matrix , dp);
        if(solve(i+1 , j-1 , n, m , matrix , dp)!=INT_MAX) leftdown =  pres+solve(i+1 , j-1 , n, m , matrix , dp);
        int rightdown = INT_MAX;
        if(solve(i+1 , j+1 ,n, m , matrix , dp)!=INT_MAX)  rightdown =  pres+solve(i+1 , j+1 ,n, m , matrix , dp);

        return dp[i][j] = min(down , min(leftdown , rightdown));

    }
    

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix.size();

        vector<vector<int>> dp(n, vector<int>(m, 0));

        // Base case: last row
        for (int j = 0; j < m; j++) {
            dp[n - 1][j] = matrix[n - 1][j];
        }

        // Fill from second-last row to first row
        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j < m; j++) {
                int pres = matrix[i][j];

                int down = pres + dp[i + 1][j];

                int leftdown = INT_MAX;
                if (j - 1 >= 0)
                    leftdown = pres + dp[i + 1][j - 1];

                int rightdown = INT_MAX;
                if (j + 1 < m)
                    rightdown = pres + dp[i + 1][j + 1];

                dp[i][j] = min(down, min(leftdown, rightdown));
            }
        }

        int mini = INT_MAX;

        // Minimum path can start at any first-row column
        for (int j = 0; j < m; j++) {
            mini = min(mini, dp[0][j]);
        }

        return mini;
    }


};