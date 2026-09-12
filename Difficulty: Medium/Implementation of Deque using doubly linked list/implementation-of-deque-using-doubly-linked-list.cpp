class Node {
  public:
    int data;
    Node* prev;
    Node* next;

    Node(int x) {
        data = x;
        prev = next = nullptr;
    }
};

class myDeque {

  public:
    Node *front ;
    Node *rear ;
    int len;
    
    myDeque() {
        // Initialize your data members
        front = rear = nullptr;
        len = 0;
    }

    void insertFront(int x) {
        // Insert element at the front
        Node*newNode = new Node(x);
        if(len==0 || front==nullptr) {
            front = newNode;
            rear = newNode;
        }else{
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }
        len++;
        
    }

    void insertRear(int x) {
        // Insert element at the rear
        Node *newNode = new Node(x);
        if(rear==nullptr){
            rear = newNode;
            front = newNode;
        }else{
            newNode->prev = rear;
            rear->next = newNode;
            rear = newNode;
        }
        len++;
    }

    void deleteFront() {
        // Delete element from the front
        if(front==nullptr) return;
        
        Node * dup = front;
        front = front->next;
        if(front!=nullptr) front->prev = nullptr;
        dup->next = nullptr;
        len--;
        delete dup;
        if(len==0) front = rear = nullptr;
        
        
        
    }

    void deleteRear() {
        // Delete element from the rear
        if(len==0) return ;
        
        Node * dup = rear;
        rear = rear->prev;
        if(rear!=nullptr) rear->next = nullptr;
        dup->prev = nullptr;
        delete dup;
        len--;
        if(len==0) front = rear = nullptr;
    }

    int getFront() {
        // Return front element (-1 if empty)
        if(len==0 || front==nullptr) return -1;
        
        return front->data;
    }

    int getRear() {
        // Return rear element (-1 if empty)
        if(len==0 || rear==nullptr) return -1;
        
        return rear->data;
    }
    
};
