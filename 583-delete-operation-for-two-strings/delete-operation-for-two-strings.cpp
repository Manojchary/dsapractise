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

    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        int lcslen = longestCommonSubsequence(word1 , word2);
        // on dry run we 
        // deletions = n-lcslen;
        // insertions = m - lcslen;
        // res = deletoins+insetions = n+m-2lcslen;

        return n+m-2*lcslen;
    }
};