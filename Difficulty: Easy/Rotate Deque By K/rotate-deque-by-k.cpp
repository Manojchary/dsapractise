class Solution {
    public:
      void rotateDeque(deque<int>& dq, int type, int k) {
          int n = dq.size();
          k %= n;

          if (type == 1) {
              // Right rotation
              while (k--) {
                  dq.push_front(dq.back());
                  dq.pop_back();
              }
          }
          else {
              // Left rotation
              while (k--) {
                  dq.push_back(dq.front());
                  dq.pop_front();
              }
          }
      }
  };