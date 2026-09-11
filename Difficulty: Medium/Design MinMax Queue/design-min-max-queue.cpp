class SpecialQueue {

  public:
    deque<int>dq;
    deque<int>mini;
    deque<int>maxi;
    void enqueue(int x) {
        // Insert element into the queue
        dq.push_back(x);
        
        while(!maxi.empty() && x>maxi.back()){
            maxi.pop_back();
        }
        
        while(!mini.empty() && x<mini.back()){
            mini.pop_back();
        }
        mini.push_back(x);
        maxi.push_back(x);
        
    }

    void dequeue() {
        // Remove element from the queue
        int val = dq.front();
        dq.pop_front();
        if(mini.front()==val){
            mini.pop_front();
        }
        if(maxi.front()==val){
            maxi.pop_front();
        }
        
    }

    int getFront() {
        // Get front element
        if(dq.empty()) return -1;
        
        return dq.front();
    }

    int getMin() {
        // Get minimum element
        if(!mini.empty()) return mini.front();
        
        return -1;
    }

    int getMax() {
        // Get maximum element
        if(!maxi.empty()) return maxi.front();
        
        return -1;
        
    }
};