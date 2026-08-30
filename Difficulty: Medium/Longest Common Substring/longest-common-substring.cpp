class Solution {
  public:
    int longCommSubstr(string& text1, string& text2) {
        // code here
        int n = text1.size();
        int m = text2.size();
        int res = 0;
        vector<vector<int>>dp(n+1, vector<int>(m+1 , 0));
        for(int i1 = 1 ; i1<=n ; i1++){
            for(int i2 = 1 ; i2<=m ; i2++){

                if(text1[i1-1]==text2[i2-1]) {
                    
                    dp[i1][i2] = 1+dp[i1-1][i2-1];
                    res = max( res , dp[i1][i2]);
                }  // if met add and move futher ;

                else{
                    dp[i1][i2] = 0;
                }
            }
        }



        return res;
    }
};