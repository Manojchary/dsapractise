class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& nums, int k) {
        // code here
        if(k==1) return nums;
        
        vector<int>res;
        deque<int>dq;
        int n = nums.size();
        for(int i = 0 ; i<n ; i++){
            if(!dq.empty() && dq.front()<=i-k){
                dq.pop_front();
            }// if dq's front out of window we remove
            
            while(!dq.empty() && nums[i]>nums[dq.back()]){// removing all elements from back whose value is lesss then present idx's val
                dq.pop_back();
            }
            
            dq.push_back(i);
            if(i>=k-1) res.push_back(nums[dq.front()]);
        }
        
        return res;
    }
};