class myDeque {

  public:
    vector<int>arr;
    int front , rear ;
    int size;
    int count;
    myDeque(int n) {
        // Initialize your data members
        arr.resize(n);
        front = 0 ;
        rear = n-1;
        size = n;
        count = 0;
        
    }

    void insertFront(int x) {
        // Insert element at the front
        front = (front-1+size)%size;
        arr[front] = x;
        count++;
    }

    void insertRear(int x) {
        // Insert element at the rear
        rear = (rear+1)%size;
        arr[rear] = x;
        count++;
    }

    void deleteFront() {
        // Delete element from the front
        if(count==0) return ;
        
        front = (front+1)%size;
        count--;
        
    }

    void deleteRear() {
        // Delete element from the rear
        if(count==0) return;
        
        rear = (rear-1+size)%size;
        count--;
        
    }

    int frontEle() {
        // Get the front element
        if(count==0) return -1;
        
        
        return arr[front];
        
    }

    int rearEle() {
        // Get the rear element
        if(count==0) return -1;
        
        return arr[rear];
    }
};