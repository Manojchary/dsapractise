
class myStack {

  public:
    int len = 0;
    Node* front;

    myStack() {
        front = new Node(-1);
    }

    bool isEmpty() {
        return front->data == -1;
    }

    void push(int x) {
        Node* f = new Node(x);
        f->next = front;
        front = f;
        len++;
    }

    void pop() {
        Node* temp = front;
        front = front->next;
        temp->next = nullptr;
        delete temp;
        len--;
    }

    int peek() {
        return front->data;
    }

    int size() {
        return len;
    }
};
