class Solution {
  public:
    int smallestSubWithSum(int x, vector<int>& arr) {
        int n = arr.size();
        int res = INT_MAX;
        int j = 0;
        int sum = 0;
        
        for(int i = 0 ; i<n ; i++){
            sum+=arr[i];
            
            while(sum>x && j<=i){
                res = min(res , i-j+1);
                sum-=arr[j];
                j++;
            }
            
        }
        if(res==INT_MAX) return 0;
        return res;
    }
};