class Solution {
  public:
    // just using the tabiluation ot optimize the ASC
    
    int solve(int idx , vector<int>& arr , int target , vector<vector<int>>&dp){
// if sum == 0 meaans there are elemnents in not taaken choice the sum is k alrady
        
        if (idx == 0) {
            if (target == 0 && arr[0] == 0)
                return 2;
            if (target == 0 || arr[0] == target)
                return 1;
            return 0;
        }
        
        
        if(dp[idx][target]!=-1) return dp[idx][target];
        
        
        
        int nottake = solve(idx-1 , arr , target , dp);
        int take = 0;
        if(arr[idx]<=target){
            take = solve(idx-1 , arr , target-arr[idx] , dp);
            
        }
        return dp[idx][target] = take + nottake;
        
        
    }
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        //vector<vector<int>>dp( n , vector<int>(target+1 , 0));
        
        // definging the base cases
        vector<int>prev(target+1 , 0) , curr(target+1 , 0);
        
        
        
        if (arr[0] == 0)
           prev[0] = 2;
        else
           prev[0] = 1;

        if (arr[0] != 0 && arr[0] <= target)
            prev[arr[0]] = 1;
        
        
        
        for(int idx = 1 ; idx<n ; idx++){
            for(int sum = 0 ; sum<=target; sum++){
                int nottake = prev[sum];
                int take = 0;
                if(arr[idx]<=sum){
                    take = prev[sum-arr[idx]];
                    
                }
               curr[sum] = take+nottake;
                
            }
            prev = curr;
        }
        return prev[target];
        
    }
};