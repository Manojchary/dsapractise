class Solution {
public:
    int solve(int idx , int tobuy  , int k , vector<int>&prices , int n ,  vector<vector<vector<int>>>&dp){
        if(idx==n || k==0) return 0;

        if(dp[idx][tobuy][k]!=-1) dp[idx][tobuy][k];
        int profit = 0;
        if(tobuy){
            profit = max(-prices[idx]+solve(idx+1 , 0 , k ,  prices , n , dp ) , 0+solve(idx+1, 1 , k, prices , n , dp));

        }else{
            profit = max(prices[idx]+solve(idx+1 , 1 , k-1 , prices , n , dp) , 0+solve(idx+1 , 0 , k , prices , n , dp));
        }

        return dp[idx][tobuy][k] = profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        int  n = prices.size();

        //vector<vector<vector<int>>>dp(n+1 , vector<vector<int>>(2 , vector<int>(k+1 , 0)));
        vector<vector<int>>after(2 , vector<int>(k+1 , 0));
        vector<vector<int>>curr(2 , vector<int>(k+1 , 0));
        
        for(int idx = n-1 ; idx>=0 ;idx--){
            for(int tobuy = 0 ; tobuy<=1 ; tobuy++){
                for(int cap = 1 ; cap<=k ; cap++){
                    
                    int profit = 0;
                    if(tobuy){
                        profit = max(-prices[idx]+after[0][cap] , 0+after[1][cap]);

                    }else{
                        profit = max(prices[idx]+after[1][cap-1] , 0+after[0][cap]);
                    }

                curr[tobuy][cap] = profit;
                }
            }
            after = curr;

        }
        return curr[1][k];
    }
};