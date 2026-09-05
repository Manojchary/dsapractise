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
        int m = p.size();
        int n = s.size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return solve(m - 1, n - 1, p, s, dp);
    }
};