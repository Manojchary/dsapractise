class Solution {
  public:   
    
    int nthFibonacci(int n) {
        // code here
        if(n==0 || n==1 ) return n;
        int i = 0  , j = 1;
        for(int k = 2 ; k<=n; k++){
            int sum = i+j;
            i = j;
            j = sum;
            
        }
        
        return j;
    }
};