class Solution {
  public:
    // s1-s2 = d;->1
    // s1+s2 = totalsum;
    // s1 = totalsum-s2 -> 2
    // 2 in 1; 
    // s2 = (totalsum-d)/2 which is == k so we need to count the subbarrays whole sum is == k
    // totalsum-s2-s2 = d;
    
    
    //using memorization usingg dp
    int solve(int idx , vector<int>& arr , int target , vector<vector<int>> &dp ){
        
        if(idx==0){
            
            if(target==0 && arr[0]==0) return 2;
            
            else if (target==0 || arr[0]==target) return 1;
            
            return 0;
            
        }
        
        if(dp[idx][target]!=-1) return dp[idx][target];
        
        
        int nottake = solve( idx-1 , arr, target , dp);
        
        int take = 0 ;
        
        if ( arr[idx]<= target) take = solve( idx -1 , arr , target-arr[idx] , dp );
        
        return dp[idx][target] = take+nottake;
    }
    
    
    
    
    
    int countPartitions(vector<int>& arr, int diff) {
        // Code here
        int n = arr.size();
        int totalsum = 0;
        
        for(int i = 0 ;i<n ; i++){
            totalsum+=arr[i];
        }
        
        int target = (totalsum-diff)/2;
        
        if((totalsum-diff)<0 || (totalsum-diff)%2 ) return 0;
        
        vector<vector<int>>dp(n , vector<int>(target+1 , -1));// target + 1 Bro don't forget 
        
        return solve(n-1 , arr , target , dp );
        
    }
};