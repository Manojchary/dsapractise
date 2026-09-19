class Solution {
  public:
    int longestCommonSubsequence(string text1, string text2 , int n  , int m) {

        vector<vector<int>>dp(n+1, vector<int>(m+1 , 0));
        for(int i1 = 1 ; i1<=n ; i1++){
            for(int i2 = 1 ; i2<=m ; i2++){

                if(text1[i1-1]==text2[i2-1]) dp[i1][i2] = 1+dp[i1-1][i2-1]; // if met add and move futher ;

                else dp[i1][i2] = max(dp[i1-1][i2] , dp[i1][i2-1]);
            }
        }



        return dp[n][m];

    }
    int findMinCost(string &s1, string &s2, int costS1, int costS2) {
        // code here
        int n = s1.size();
        int m = s2.size();
        
        int lcs = longestCommonSubsequence(s1 , s2 , n , m);
        int leftn = n-lcs;
        int leftm = m-lcs;
        
        
        return leftn*costS1+leftm*costS2;
        
        
    }
};