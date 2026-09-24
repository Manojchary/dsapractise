class Solution {
public:
    long long solve(int i, int n, vector<int>& nums, vector<long long>& dp) {
        // Already at or beyond the last index
        if (i >= n - 1)
            return 0;

        // Already calculated
        if (dp[i] != -1)
            return dp[i];

        long long minJumps = INT_MAX;

        // Try every position we can jump to
        for (int j = i + 1; j <= i + nums[i]; j++) {

            long long jumps = 1 + solve(j, n, nums, dp);

            minJumps = min(minJumps, jumps);
        }

        return dp[i] = minJumps;
    }

    int jump(vector<int>& nums) {
        int n = nums.size();

        if (n == 1)
            return 0;

        vector<long long> dp(n, -1);

        return solve(0, n, nums, dp);
    }
};