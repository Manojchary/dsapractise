class Solution {
public:
    int digitsum(int n){

        int temp = n;
        int res = 0;

        while(temp){
            int digit = temp%10;
            temp = temp/10;
            res+=digit;
        }

        return res;

    }
    int digitprod(int n){
        int temp = n;
        int res = 1;
        while(temp){
            int digit = temp%10;
            temp = temp/10;
            res*=digit;
        }
        return res;

    }
    bool checkDivisibility(int n) {
        int dsum = digitsum(n);
        int dprod = digitprod(n);
        int sum = dsum+dprod;
        return n%sum==0;
    }
};