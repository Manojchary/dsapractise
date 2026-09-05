class Solution {
public:
    // with only plane recursion with memoization
    
    int solve(int i1 , int i2 , string s1 , string s2 , vector<vector<int>>&dp){// min no of operations need to done;
        
        if(i1<0){
            return i2+1;  // means example need to convert "" to "at" so we need to insert the remaining so i2+1 insertion need to made ;
        }

        if(i2<0){
            return i1+1;  //example "abc" to "" so we need to delete remaning so we delete i1+1
        }

        if(dp[i1][i2]!=-1) return dp[i1][i2];

        if(s1[i1]==s2[i2]){  // if we have match we do nothing means as we are finding the min no operations to convert the remaniing not mathching part
            return dp[i1][i2] = 0+solve(i1-1 , i2-1 , s1 , s2 , dp);
        }

        // not matching case


        int insert = 1+solve(i1 , i2-1 , s1 , s2 , dp);// assuming that there is a common eleemnt in both

        int deletion = 1+solve(i1-1 , i2 , s1 , s2 , dp); // assuming that we deleted the element from the s1;

        int replace = 1+solve(i1-1 , i2-1 , s1 , s2 , dp);// if both are notmathing we need to replacing the present onces

        return dp[i1][i2] = min(insert , min(deletion , replace));
    }
    int minDistance(string word1, string word2) {

        int n = word1.size();
        int m = word2.size();
        vector<vector<int>>dp(n , vector<int>(m , -1));

        return solve(n-1 , m-1 , word1 , word2 , dp);
    }
};