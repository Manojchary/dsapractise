class Solution {
public:
    // solved using normal recursion with memorization
    bool solve(int idx, int target, vector<int>& arr , vector<vector<int>>&dp) {
        if (target == 0)
            return true;

        if (idx == 0)
            return arr[0] == target;
            
        if(dp[idx][target]!=-1) return dp[idx][target];
        
        bool take = false;

        if (target >= arr[idx])
            take = solve(idx - 1, target - arr[idx], arr , dp);

        bool nottake = solve(idx - 1, target, arr , dp);

        return dp[idx][target] = take || nottake;
    }

    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        
        vector<vector<int>>dp(n , vector<int>(sum+1 , -1));
        
        
        if (n == 0)
            return false;
        

        return solve(n - 1, sum, arr ,dp);
    }
};