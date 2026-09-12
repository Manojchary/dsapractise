/* Structure of linked list Node
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    int getCount(Node* head) {
        // Code here
        if(head==nullptr) return 0;
        Node * t = head;
        int c = 0;
        while(t){
            t = t->next;
            c++;
        }
        return c;
        
    }
};