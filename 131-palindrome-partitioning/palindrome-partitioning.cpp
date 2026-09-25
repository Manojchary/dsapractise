class Solution {
public:
    bool isPalindrome(string s){
        int n = s.size();
        int i = 0 , j = n-1;
        while(i<=j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    void solve(int i , int n , string s  , vector<string> dp , vector<vector<string>>&res){
        if(i==n) {
            res.push_back(dp);// when base case occus the dp of palindromes are stored in res;
            return ;
        }

        string temp = "";

        for(int j = i ; j<n ; j++){
            temp+=s[j];
            if(isPalindrome(temp)){
                dp.push_back(temp);//stores the present palindromes;

                solve(j+1 , n , s , dp , res);// trying to find other palindromes;
    
                dp.pop_back();
            }
        }

    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>res;
        int n = s.size();
        vector<string>dp;
        solve(0 , n , s , dp , res );

        return res;
    }
};