
class Btrie{
    public:
    vector<Btrie*>children;
    Btrie(){
        children = vector<Btrie*>(2 , nullptr);
    }
};

class Solution {
public:
    void insertlikebin(Btrie*root , int num){
        Btrie*curr = root;
        for(int i = 30 ; i>=0 ; i--){
            int bit = (num>>i) & 1;
            if(curr->children[bit]==nullptr){
                curr->children[bit] = new Btrie();
            }
            curr = curr->children[bit];
        }
    }
    int find_maxi_xor_in_trie(Btrie*root , int num){

        Btrie*curr = root;
        int ans = 0;

        for(int i = 30 ; i>=0 ; i--){
            int bit = (num>>i) & 1;
            if(curr->children[!bit]!=nullptr){// if we have opposite bit choosing it
                ans |= (1<<i);
                curr = curr->children[!bit];
            }else{// if now just leave
                curr = curr->children[bit];
            }
        }

        return ans;

    }
    int findMaximumXOR(vector<int>& arr) {
        int n = arr.size();
        Btrie*root = new Btrie();
        insertlikebin(root , arr[0]);
        int res = 0;
        for(int i = 1 ; i<n ; i++){
            int ans = find_maxi_xor_in_trie(root , arr[i]);
            res = max(res,ans);

            insertlikebin(root  ,arr[i]);
        }

        return res;
    }
};