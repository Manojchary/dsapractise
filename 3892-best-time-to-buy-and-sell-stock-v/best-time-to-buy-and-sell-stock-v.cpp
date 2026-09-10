class Solution {
public:
    const long long NEG = LLONG_MIN / 2;
    long long solve(int idx, int tranNo, int pos, int k,
                     vector<int>& prices, int n,
                     vector<vector<vector<long long>>>& dp) {
         if (idx >= n) {
            return (pos == 0) ? 0 : NEG;   // can't dangle an open position
        }
                        
        if (tranNo == k) return 0;

        if (dp[idx][tranNo][pos] != -1) return dp[idx][tranNo][pos];

        long long profit = 0;
        if (pos == 0) { // initial buy or sell
            long long buythis  = -prices[idx] + solve(idx+1, tranNo, 1, k, prices, n, dp);
            long long sellthis =  prices[idx] + solve(idx+1, tranNo, 2, k, prices, n, dp);
            long long skip     =  0 + solve(idx+1, tranNo, 0, k, prices, n, dp);

            profit = max(buythis, max(sellthis, skip));

        } else if (pos == 1) { // sell
            long long sellthis = prices[idx] + solve(idx+1, tranNo+1, 0, k, prices, n, dp);
            long long skip     = 0 + solve(idx+1, tranNo, 1, k, prices, n, dp);
            profit = max(sellthis, skip);

        } else { // buythis
            long long buythis = -prices[idx] + solve(idx+1, tranNo+1, 0, k, prices, n, dp);
            long long skip    = 0 + solve(idx+1, tranNo, 2, k, prices, n, dp);
            profit = max(buythis, skip);
        }

        return dp[idx][tranNo][pos] = profit;
    }

    long long maximumProfit(vector<int>& prices, int k) {
        long long n = prices.size();
        vector<vector<vector<long long>>> dp(n+1, vector<vector<long long>>(k+1, vector<long long>(3, NEG)));

        for (int tranNo = 0; tranNo <= k; tranNo++) {
            dp[n][tranNo][0] = 0;
            dp[n][tranNo][1] = NEG;
            dp[n][tranNo][2] = NEG;
            if(tranNo==k){
                dp[n][tranNo][1] = 0;
                dp[n][tranNo][2] = 0;
            }
        }
        for (int idx = n - 1; idx >= 0; idx--) {

    // Same as: if (tranNo == k) return 0;
    dp[idx][k][0] = 0;
    dp[idx][k][1] = 0;
    dp[idx][k][2] = 0;

    for (int tranNo = 0; tranNo < k; tranNo++) {

        for (int pos = 0; pos <= 2; pos++) {

            long long profit = 0;

            if (pos == 0) {

                long long buythis =
                    -prices[idx] + dp[idx + 1][tranNo][1];

                long long sellthis =
                    prices[idx] + dp[idx + 1][tranNo][2];

                long long skip =
                    dp[idx + 1][tranNo][0];

                profit = max({buythis, sellthis, skip});

            }
            else if (pos == 1) {

                long long sellthis =
                    prices[idx] + dp[idx + 1][tranNo + 1][0];

                long long skip =
                    dp[idx + 1][tranNo][1];

                profit = max(sellthis, skip);
            }
            else {

                long long buythis =
                    -prices[idx] + dp[idx + 1][tranNo + 1][0];

                long long skip =
                    dp[idx + 1][tranNo][2];

                profit = max(buythis, skip);
            }

            dp[idx][tranNo][pos] = profit;
        }
    }
}
        return dp[0][0][0];
    }
};