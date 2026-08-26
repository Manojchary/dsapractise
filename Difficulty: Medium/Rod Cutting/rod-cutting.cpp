class Solution {
  public:
    int solve(int i , int remaininglen , vector<int>&price , vector<vector<int>>&dp ){// here i defines the len of rod we took means i+1 len we took now 
        
        int currpiecelen = i+1;
        
        if(i==0){// if the length to take is == 1
            return remaininglen*price[i];// 
        }
        
        if(dp[i][remaininglen]!=-1) return dp[i][remaininglen];
        
        int nottake = solve(i-1 , remaininglen, price , dp );
        
        int take = INT_MIN;
        
        if(currpiecelen<=remaininglen){
            take = price[i]+solve(i , remaininglen-currpiecelen , price , dp );
        }
        
        return dp[i][remaininglen] = max(take , nottake);
    }
    int cutRod(vector<int> &price) {
        // code here
        int n = price.size();
        
        vector<vector<int>>dp(n , vector<int>(n+1 , -1));
        
        return solve(n-1 , n , price , dp);
        
    }
};