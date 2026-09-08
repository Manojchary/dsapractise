class Solution {
public:
    int solve(int idx , int tobuy  , int cap , vector<int>&prices , int n ,  vector<vector<vector<int>>>&dp){
        if(idx==n || cap==0) return 0;

        if(dp[idx][tobuy][cap]!=-1) dp[idx][tobuy][cap];
        int profit = 0;
        if(tobuy){
            profit = max(-prices[idx]+solve(idx+1 , 0 , cap ,  prices , n , dp ) , 0+solve(idx+1, 1 , cap, prices , n , dp));

        }else{
            profit = max(prices[idx]+solve(idx+1 , 1 , cap-1 , prices , n , dp) , 0+solve(idx+1 , 0 , cap , prices , n , dp));
        }

        return dp[idx][tobuy][cap] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        //vector<vector<vector<int>>>dp(n+1 , vector<vector<int>>(2 , vector<int>(3 , 0)));
        
        vector<vector<int>>after(2 , vector<int>(3 , 0));
        vector<vector<int>>curr(2 , vector<int>(3 , 0));

        for(int idx = n-1 ; idx>=0 ; idx--){
            for(int tobuy = 0 ; tobuy<=1 ; tobuy++){
                for(int cap = 1 ; cap<=2 ; cap++){

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
        return after[1][2];
    }
};