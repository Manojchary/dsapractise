class Solution {
public:
    int solve(int idx , int tobuy ,  int n , vector<int>& prices , int fee , vector<vector<int>>&dp){
        if(idx==n ) return 0;

        if(dp[idx][tobuy]!=-1) return dp[idx][tobuy];

        long long profit = 0;
        
        if(tobuy){
            long long buythis =-prices[idx]+solve( idx+1 , 0 , n , prices , fee , dp);
            long long buynext = 0+solve(idx+1 , 1 , n , prices , fee , dp);
            profit = max(buythis , buynext); 
        }else{
            long long sellthis = prices[idx]-fee+solve(idx+1 , 1 , n , prices , fee , dp);
            long long sellnext = 0+solve(idx+1 , 0 , n , prices , fee , dp);
            profit = max(sellthis , sellnext);
        }

        return dp[idx][tobuy] = profit;

    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        
        vector<vector<int>>dp(n+1 , vector<int>(2 , 0));

        for(int idx = n-1 ; idx >= 0 ; idx--){
            for(int tobuy = 0 ; tobuy<=1 ; tobuy++){
                long long profit = 0;
        
                if(tobuy){
                    long long buythis =-prices[idx]+dp[idx+1][0];
                    long long buynext = 0+dp[idx+1][1];
                    profit = max(buythis , buynext); 
                }else{
                    long long sellthis = prices[idx]-fee +dp[idx+1][1];
                    long long sellnext = 0+dp[idx+1][0];
                    profit = max(sellthis , sellnext);
                }
                dp[idx][tobuy] = profit;
            }
        }
        return dp[0][1];
    }
};