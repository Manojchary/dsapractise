class Solution {
public:
    int countPartitions(vector<int>& arr, int diff) {
        int n = arr.size();
        int totalSum = 0;

        for (int x : arr) {
            totalSum += x;
        }

        // We need:
        // S1 - S2 = diff
        // S1 + S2 = totalSum
        //
        // Therefore:
        // S2 = (totalSum - diff) / 2

        if (totalSum - diff < 0 || (totalSum - diff) % 2 != 0) {
            return 0;
        }

        int target = (totalSum - diff) / 2;

        vector<int> prev(target + 1, 0);
        vector<int> curr(target + 1, 0);

        // Base case
        if (arr[0] == 0) {
            prev[0] = 2;  // take 0 OR don't take 0
        } else {
            prev[0] = 1;

            if (arr[0] <= target) {
                prev[arr[0]] = 1;
            }
        }

        for (int idx = 1; idx < n; idx++) {
            fill(curr.begin(), curr.end(), 0);

            for (int sum = 0; sum <= target; sum++) {
                int notTake = prev[sum];

                int take = 0;
                if (arr[idx] <= sum) {
                    take = prev[sum - arr[idx]];
                }

                curr[sum] = take + notTake;
            }

            prev = curr;
        }

        return prev[target];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        // example +1 -1 +2 -3
        // can be written as 1+2-1-3 , so S1-S2 = TARGET;
        //THATS THE PATTERN OF PARTIIOING;
        
        return countPartitions(nums , target);
    }
};