class Solution {
public:
    // using recursion with idx format take and not take by also taking comination of prev and curr idx ,
    int solve(int prev , int idx , vector<int>&nums , int n  , vector<vector<int>>&dp){

        if(idx>=n ) return 0;

        if(dp[prev+1][idx]!=-1) return dp[prev+1][idx];
        // not take 
        
        int nottake = 0+solve(prev , idx+1 , nums , n , dp);

        //take
        int take = 0;

        if(prev==-1 || nums[prev]<nums[idx]) take = 1+solve(idx , idx+1 , nums , n , dp);/// we took that prev so curr idx is the next prev;

        return dp[prev+1][idx] = max(nottake , take);

    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>>dp(n+1 , vector<int>(n+1 , 0));

        //return solve(-1 , 0 , nums , nums.size() , dp);

        //solving using tabulation

        for(int idx = n-1 ; idx>=0 ; idx--){
            for(int prev = -1 ; prev<idx ; prev++){
                int nottake = dp[idx+1][prev+1];

                int take = 0;

                if(prev==-1 || nums[prev]<nums[idx]) take = 1+ dp[idx+1][idx+1];

                dp[idx][prev+1] = max(take , nottake);
            }
        }

        return dp[0][0];


    }
};