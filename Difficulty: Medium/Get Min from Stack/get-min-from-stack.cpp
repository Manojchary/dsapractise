class SpecialStack {
  public:
    stack<int>st;
    stack<int>mini;
    SpecialStack() {
        // Define Stack
    }

    void push(int x) {
        // Add an element to the top of Stack
        st.push(x);
        if(mini.empty()){
            mini.push(x);
        }else{
            int p = min(mini.top() , x);
            mini.push(p);
        }
    }

    void pop() {
        // Remove the top element from the Stack
        if(mini.empty()) return ;
        mini.pop();
        st.pop();
    }

    int peek() {
        // Returns top element of the Stack
        if(st.empty()) return -1;
        return st.top();
    }

    bool isEmpty() {
        // Check if stack is empty
        return st.empty();
    }

    int getMin() {
        // Finds minimum element of Stack
        if(mini.empty()) return -1;
        return mini.top();
    }
};