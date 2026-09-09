class Solution {
public:
    int solve(int idx ,  int tranNo  , int k ,  vector<int>&prices , int n ,  vector<vector<int>>&dp){
        if(idx==n || tranNo==k) return 0;

        if(dp[idx][tranNo]!=-1) return dp[idx][tranNo];

        int tobuy = tranNo%2;
        int profit = 0;
        if(!tobuy){
            profit = max(-prices[idx]+solve(idx+1 , tranNo+1 , k ,  prices , n , dp ) , 0+solve(idx+1, tranNo , k , prices , n , dp));// max( vuy this , notbuy this)

        }else{
            profit = max(prices[idx]+solve(idx+1 , tranNo+1 , k , prices , n , dp) , 0+solve(idx+1 , tranNo , k , prices , n , dp));
        }

        return dp[idx][tranNo] = profit;
        
    }
    int maxProfit(int k, vector<int>& prices) {
        int  n = prices.size();

        vector<vector<int>>dp(n , vector<int>(k*2+1 , -1));\

        return solve(0 , 0 , k*2 , prices , n , dp);
    }
};