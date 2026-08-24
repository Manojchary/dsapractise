class Solution {
public:
    // using the take and nottake approach using recursion with memorization


    int solve(int idx , int target ,vector<int>&coins , vector<vector<int>>&dp){

        if(idx==0) return (target%coins[idx]==0);// return one if condition met;

        if( dp[idx][target]!=-1 ) return dp[idx][target];

        int nottake = solve(idx-1 , target , coins , dp);

        int take = 0;

        if(coins[idx]<=target) take = solve(idx , target-coins[idx] , coins , dp );

        return dp[idx][target] = take+nottake;

    }
    int change(int amount, vector<int>& coins) {

        int n = coins.size();

        vector<vector<int>>dp(n , vector<int>(amount+1 , -1));

        return solve(n-1 , amount , coins , dp);
        
    }
};