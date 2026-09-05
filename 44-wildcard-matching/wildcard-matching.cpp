class Solution {
public:
    bool isMatch(string s, string p) {

        int n = p.size();
        int m = s.size();

        // can p converted into s;

        //vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));

        // using 1 based indexing

        vector<bool>dp(m+1 , false) , curr(m+1 , false);

        dp[0] = true;// if both get exhausted it will be true , means indirectly all are matched;


        // for(int i = 0 ; i<=n ; i++){
        //     bool flag = true;
        //     for (int k = 1; k <= i; k++) {
        //         if (p[k-1] != '*')
        //             flag = false;
        //     }
        //     dp[i][0] = flag;
        // }

        for(int i = 1 ; i<=n ; i++){
            vector<bool>curr(m+1 , false);
            bool flag = true;
            for (int k = 1; k <= i; k++) {
                if (p[k-1] != '*')
                    flag = false;
            }
            curr[0] = flag;

            for(int j = 1; j<=m ; j++){
                if (p[i-1] == s[j-1] || p[i-1] == '?') {
                    curr[j] = dp[j - 1];
                }
                else if (p[i-1] == '*') {
                    curr[j] =
                        dp[j] ||   // '*' matches empty
                        curr[j - 1] ;      // '*' matches s[j]
                }
            }
            dp = curr;
        }


        return dp[m];
    }
};
