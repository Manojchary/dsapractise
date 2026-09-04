class Solution {
public:
    //solving using plane recursion with memoization 
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
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>>dp(n , vector<int>(m+1 , -1));

        return solve(n-1 , m-1 , s , t , dp);
    }
};