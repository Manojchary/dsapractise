class Solution {
public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();

        if (n == 0)
            return false;

        vector<vector<bool>> dp(n, vector<bool>(sum + 1, false));

        // target = 0 is always possible
        for (int i = 0; i < n; i++) {
            dp[i][0] = true;
        }

        // First element
        if (arr[0] <= sum) {
            dp[0][arr[0]] = true;
        }

        // Fill the table
        for (int idx = 1; idx < n; idx++) {
            for (int target = 1; target <= sum; target++) {

                bool take = false;

                if (target >= arr[idx])
                    take = dp[idx - 1][target - arr[idx]];

                bool nottake = dp[idx - 1][target];

                dp[idx][target] = take || nottake;
            }
        }

        return dp[n - 1][sum];
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return false;

        int sum = 0;
        for(int i = 0 ; i<n ; i++){
            sum+=nums[i];
        }

        if(sum%2==0){
            int target = sum/2;
            return isSubsetSum(nums , target);
        }
        return false;
        
    }
};