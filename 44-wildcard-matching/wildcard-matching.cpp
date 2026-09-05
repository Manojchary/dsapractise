class Solution {
public:
    bool solve(int i, int j, string& p, string& s,
               vector<vector<int>>& dp) {

        // Both pattern and string exhausted
        if (i < 0)
            return j < 0;

        // String exhausted: remaining pattern must be all '*'
        if (j < 0) {
            for (int k = 0; k <= i; k++) {
                if (p[k] != '*')
                    return false;
            }
            return true;
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        // Normal character or '?'
        if (p[i] == s[j] || p[i] == '?') {
            return dp[i][j] = solve(i - 1, j - 1, p, s, dp);
        }

        // '*'
        if (p[i] == '*') {
            return dp[i][j] =
                solve(i - 1, j, p, s, dp) ||   // '*' matches empty
                solve(i, j - 1, p, s, dp);      // '*' matches s[j]
        }

        return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {
        int n = p.size();
        int m = s.size();

        // can p converted into s;

        vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));

        // using 1 based indexing

        dp[0][0] = true;// if both get exhausted it will be true , means indirectly all are matched;


        for(int i = 0 ; i<=n ; i++){
            bool flag = true;
            for (int k = 1; k <= i; k++) {
                if (p[k-1] != '*')
                    flag = false;
            }
            dp[i][0] = flag;
        }

        for(int i = 1 ; i<=n ; i++){
            for(int j = 1; j<=m ; j++){
                if (p[i-1] == s[j-1] || p[i-1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else if (p[i-1] == '*') {
                    dp[i][j] =
                        dp[i - 1][j] ||   // '*' matches empty
                        dp[i][j - 1] ;      // '*' matches s[j]
                }
            }
        }


        return dp[n][m];
    }
};