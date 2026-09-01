class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>>dp(n+1, vector<int>(m+1 , 0));
        for(int i1 = 1 ; i1<=n ; i1++){
            for(int i2 = 1 ; i2<=m ; i2++){

                if(text1[i1-1]==text2[i2-1]) dp[i1][i2] = 1+dp[i1-1][i2-1]; // if met add and move futher ;

                else dp[i1][i2] = max(dp[i1-1][i2] , dp[i1][i2-1]);
            }
        }
        

        
        return dp[n][m];
        
    }
    int longestpalidromicsubsequence(string s1){

        string s2 = s1;

        reverse(s2.begin() , s2.end());

        return longestCommonSubsequence(s1 , s2);

    }
    int minInsertions(string s) {
        // so here we are including two algos 
        // 1 lcs
        // 2 lpss longest palidromic subsequence

        int n = s.size();
        int lpslen = longestpalidromicsubsequence(s);
        // once dry run 


        return n-lpslen;
    }
};