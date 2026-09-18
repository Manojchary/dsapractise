class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n , 1);
        vector<int>count(n, 1);
        int maxi = 1;
        for(int i = 0 ; i<n ; i++){//idx
            for(int p = 0 ; p<i ; p++){// prev
                if(nums[p]<nums[i]){
                    if(dp[p]+1>dp[i]){
                        dp[i] = dp[p]+1;
                        count[i] = count[p];
                    }else if(dp[p]+1==dp[i]){
                        count[i]+=count[p];
                    }
                }
                maxi = max(dp[i] , maxi);
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (dp[i] == maxi) {
                ans += count[i];
            }
        }

        return ans;
        
    }
};