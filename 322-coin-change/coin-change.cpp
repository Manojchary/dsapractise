class Solution {
public:
    // the approach is simple using memrization with the basic recursion  
    int solve(int idx , int target , vector<int>& arr , vector<vector<int>>&dp){
        
        if(idx==0){
            
            if(target%arr[idx]==0) return target/arr[idx]; // if the first element can divide return times 

            else return 1e9;// else 

        }

        if(dp[idx][target]!=-1) return dp[idx][target];

        int nottake = solve(idx -1 , target , arr , dp);// don't take just move to before 

        int take = 1e9;

        if(arr[idx]<=target){

            take = 1+solve(idx , target-arr[idx] , arr , dp);// take this index and substract the curr so we are using it, and while adding one we are using it
        }

        return dp[idx][target] = min(take , nottake );
    }
    int coinChange(vector<int>& coins, int amount) {


        int n = coins.size();
        vector<vector<int>>dp(n , vector<int>(amount+1 , -1));

        int res = solve(n-1 , amount , coins , dp);
        return res >=1e9 ? -1 : res ;
    }
};