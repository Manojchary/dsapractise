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

        // vector<vector<unsigned long long>> dp(n, vector<unsigned long long>(amount + 1, 0));
        vector<int>dp(amount+1 , 0);

        // Base case:
        // Using only coins[0], there is exactly one way
        // if amount is divisible by coins[0].
        for (long long t = 0; t <= amount; t++) {
            if (t % coins[0] == 0)
                dp[t] = 1;
        }

        // Fill the DP table
        for (long long i = 1; i < n; i++) {

            for (long long t = 0; t <= amount; t++) {

                // Don't take current coin
                unsigned long long nottake = dp[t];

                // Take current coin
                // Stay at i because the coin can be reused
                unsigned long long take = 0;

                if (coins[i] <= t) {
                    take = dp[t - coins[i]];
                }

                dp[t] = take + nottake;
            }

        }

        return dp[amount];
    
        
    }
};