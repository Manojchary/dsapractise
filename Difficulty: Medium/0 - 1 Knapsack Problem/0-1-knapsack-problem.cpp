class Solution {
  public:

    // Recursion + memoization: take or not take current item
    int solve(int idx, int w, vector<int> &val, vector<int> &wt,
              vector<vector<int>>& dp) {

        // Base case: only item 0 is left
        if (idx == 0) {
            if (wt[idx] <= w) {
                return val[idx];  // Can take item 0
            } else {
                return 0;         // Cannot take item 0
            }
        }

        // Already calculated
        if (dp[idx][w] != -1)
            return dp[idx][w];

        // Don't take current item
        int nottake = solve(idx - 1, w, val, wt, dp);

        int take = INT_MIN;

        // Take current item if it fits
        if (wt[idx] <= w) {
            take = val[idx] + solve(idx - 1, w - wt[idx], val, wt, dp);
        }

        // Store and return the maximum
        return dp[idx][w] = max(take, nottake);
    }

    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = val.size();

        // dp[idx][w] = maximum value using items 0...idx with capacity w
        vector<vector<int>> dp(n, vector<int>(W + 1, -1));

        // Start from last item with full capacity
        return solve(n - 1, W, val, wt, dp);
    }
};