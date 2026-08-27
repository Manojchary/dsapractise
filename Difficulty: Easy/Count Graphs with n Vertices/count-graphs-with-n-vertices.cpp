class Solution {
  public:
    long long count(int n) {
        // code here
        long long p = (n*(n-1))/2;
        long long res = pow(2 , p);
        
        return res;
    }
};