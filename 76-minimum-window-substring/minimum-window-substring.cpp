class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<int>scount(256 , 0);
        vector<int>tcount(256 , 0);
        for(int i = 0 ; i<m ; i++){
            tcount[t[i]]++;

        }
        int i = 0 , j = 0 ;
        int res = INT_MAX;
        string ans = "";
        int start = 0;

        int count = 0;// which counts for chars which are in t;
        while(j<n){
            
            scount[s[j]]++;
            if(tcount[s[j]]!=0 && scount[s[j]]<=tcount[s[j]] ){// the element which is in t if there in s too we increase count
                count++;
            }
            // when the count matcches to the size of tcount we find the solution while count == tcountsize;
            while(count==m){
                
                if((j-i+1)<res) start = i , res = (j-i+1);

                scount[s[i]]--;
                if(tcount[s[i]]>0 && scount[s[i]]<tcount[s[i]]){
                    count--;
                }
                i++;

            }
            
            
            j++;
        }

        return res==INT_MAX ? "" : s.substr(start , res) ;
        
    }
};