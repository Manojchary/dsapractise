class Solution {
  public:
    //solving using pure recursion with memoization ;
    int solve(int idx , int w , vector<int>&wt , vector<int>&val  , vector<vector<int>>&dp ){
        
        
        if(idx==0){
            return ((int)(w/wt[idx]))*val[idx];// returning the 
        }
        
        if(dp[idx][w]!=-1) return dp[idx][w];// if previous is there return 
        
        int nottake = 0+solve(idx-1 , w , wt , val , dp);// not choosing 
        
        int take = INT_MIN;
        
        if(wt[idx]<=w){
            take = val[idx]+solve(idx , w-wt[idx] , wt , val , dp);// choosing this idx and reusing this idx if this fits well
            
        }
        
        return dp[idx][w] = max(take , nottake);// returning the best option;
        
        
    }
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n = val.size();
        vector<vector<int>>dp(n , vector<int>(capacity+1 , -1));
        
        return solve(n-1 , capacity , wt , val , dp);
        
    }
};