class Solution {
public:
    //solving using tubalation from memoization approach 

    int solve(int i1 , int i2 , string s1 , string s2 , vector<vector<int>>&dp ){
        if(i2<0) return 1; //means we found the complete target string to be there in test string s1;
        if(i1<0) return 0; // means we didn't found the complete target string 
        
        if(dp[i1][i2]!=-1) return dp[i1][i2];

        if(s1[i1]==s2[i2]){
            return dp[i1][i2] = solve(i1-1 , i2-1 , s1 , s2 , dp)+solve(i1-1 , i2 , s1 , s2 , dp);// here we are eplxing take and nottake at same time by adding their results;
        }else{
            return dp[i1][i2] = solve(i1-1 , i2 , s1 , s2 , dp);// if not match we are moving the further index
        }
    }
    int numDistinct(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<unsigned long long>>dp(n+1 , vector<unsigned long long>(m+1 , 0));

        for(int i = 0 ; i<=n ; i++){
            dp[i][0] = 1;// when j==0 means we found the complete target str;
        }

        for(int i1 = 1 ; i1<=n ; i1++){
            for(int i2 = 1 ; i2<=m ; i2++){
                if(s1[i1-1]==s2[i2-1]){// as we are choosing one based index we check i-1 , j-1
                    dp[i1][i2] = dp[i1-1][i2-1] + dp[i1-1][i2];// here we are eplxing take and nottake at same time by adding their results;
                }else{
                    dp[i1][i2] = dp[i1-1][i2];// if not match we are moving the further index
                }        
            }
        }

        return dp[n][m];
    }
};