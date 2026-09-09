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
    int maxProfit(vector<int>& prices) {
        
        vector<vector<int>>dp(prices.size() ,vector<int>(4 , -1) );
        return solve(0, 0 , 4 , prices ,  prices.size() , dp );// 2 means 4 trasation buy , sell , buy , sell ;
        
        
    }
};