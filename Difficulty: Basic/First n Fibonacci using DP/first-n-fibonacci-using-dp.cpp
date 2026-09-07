
class Solution {
public:
    const int mod = 1e9+7;
    int fibbo(int idx, vector<int>& dp) {
        if (idx == 0) return dp[0] = 0;
        if (idx == 1) {
            dp[1] = 1;
            dp[0] = 0;
            
            return dp[1];
        }

        if (dp[idx] != -1) return dp[idx];

        return dp[idx] = (fibbo(idx - 1, dp) + fibbo(idx - 2, dp))%mod;
    }

    vector<int> fibonacciNumbers(int n) {
        vector<int> dp(n + 1, -1);
        fibbo(n, dp);
        return dp;
    }
};

