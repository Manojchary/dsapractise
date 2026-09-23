class Solution {
public:
    bool isPalindrome(string &s){

        int n = s.size();
        if(n==0) return false;

        int i = 0;
        int j = n-1;
        while(i<=j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    int solve(int i , string &s , vector<int>&dp , int n ){
        
        if(i==n) return 0;

        if(dp[i]!=-1) return dp[i];

        string temp = "";

        int mini = INT_MAX;

        for(int j = i ; j<n ; j++){

            temp+=s[j];
            if(isPalindrome(temp)){
                int cost = 1+solve(j+1 , s , dp , n);
                mini = min(mini , cost);
            }

        }

        return dp[i] = mini;
        
    }
    int minCut(string &s) {
        int n = s.size();
        vector<int>dp(n , -1);

        return solve(0 , s , dp , s.size())-1;

    }
};