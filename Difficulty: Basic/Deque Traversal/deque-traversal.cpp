class Solution {
  public:
    void printDeque(deque<int> &dq) {
        // code here
        if(dq.empty()) return ;
        
        while(dq.size()!=1){
            int ele = dq.front();
            dq.pop_front();
            cout<<ele<<' ';
        }
        cout<<dq.front()<<endl;
    }
};