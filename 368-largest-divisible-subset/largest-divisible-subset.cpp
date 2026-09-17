class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {

        int n = nums.size();

        sort(nums.begin(), nums.end());

        vector<int> dp(n, 1);

        // CORRECTION: store the previous index to reconstruct the subset
        vector<int> parent(n, -1);

        // CORRECTION: track the index of the maximum subset
        int maxIdx = 0;

        for (int idx = 0; idx < n; idx++) {
            for (int prev = 0; prev < idx; prev++) {

                if (nums[idx] % nums[prev] == 0 &&
                    dp[prev] + 1 > dp[idx]) {

                    dp[idx] = dp[prev] + 1;

                    // CORRECTION: save the previous element
                    parent[idx] = prev;
                }
            }

            // CORRECTION: update index of maximum subset
            if (dp[idx] > dp[maxIdx])
                maxIdx = idx;
        }

        // CORRECTION: reconstruct the actual subset
        vector<int> res;

        while (maxIdx != -1) {
            res.push_back(nums[maxIdx]);
            maxIdx = parent[maxIdx];
        }

        // CORRECTION: reverse because reconstruction starts from the last element
        reverse(res.begin(), res.end());

        return res;
    }
};