class Solution {
public:

    // solving using only recursion 

    int solve(int idx , int tobuy , vector<int>&prices , int n , vector<vector<int>>&dp){// either buy or sell acc to "tobuy" 

        if(idx==n) return 0;

        if(dp[idx][tobuy]!=-1) return dp[idx][tobuy];

        int profit = 0;
        if(tobuy){//1
            int buythis = -prices[idx]+solve(idx+1 , 0 , prices , n  , dp);  //dry run this line , buythis idx and sell next
            int buynext = 0+solve(idx+1 , 1 , prices , n , dp);  // leave this buy next;
            profit = max(buythis , buynext);
        }else{//0
            int sellthis = prices[idx]+solve(idx+1 , 1 , prices , n , dp);// sell this again buy next;
            int sellnext = 0+solve(idx+1 , 0 , prices , n , dp); // left this sell other

            profit = max(sellthis , sellnext);
        }
        return dp[idx][tobuy] = profit;
    }
    int maxProfit(vector<int>& prices) {

        int n = prices.size();
        vector<vector<int>>dp(n+1 , vector<int>(2 ,  0));

        dp[n][0]  = dp[n][1] = 0;

        for(int idx = n-1 ; idx>=0 ; idx--){
            for(int tobuy = 0 ; tobuy<=1 ; tobuy++){
                int profit = 0;
                if(tobuy){//1
                    int buythis = -prices[idx]+dp[idx+1][0];
                    int buynext = 0+dp[idx+1][1];

                    profit = max(buythis , buynext);
                }else{//0
                    int sellthis = prices[idx]+dp[idx+1][1];

                    int sellnext = 0+dp[idx+1][0];

                    profit = max(sellthis , sellnext);
                }
                dp[idx][tobuy] = profit;
            }
        }

        return dp[0][1];

    }
};