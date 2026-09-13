class Solution {
  public:
    deque<int> dqInsertion(vector<int>& arr) {
        // code here
        int n = arr.size();
        deque<int>dq;
        if(n==0) return dq;
        for(int i = 0 ; i<n ; i++){
            dq.push_back(arr[i]);
        }
        
        return dq;
        
    }
};