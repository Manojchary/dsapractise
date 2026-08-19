class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        
        // Store only rows that actually have reserved seats
        unordered_map<int, vector<int>> seats;

        for (auto &x : reservedSeats) {
            int row = x[0];
            int seat = x[1];
            seats[row].push_back(seat);
        }

        int res = 2 * (n - seats.size());

        // Process only rows having reservations
        for (auto &[row, reserved] : seats) {

            vector<int> s(11, 0);

            for (int seat : reserved) {
                s[seat] = 1;
            }

            bool left = true;    // 2,3,4,5
            bool middle = true; // 4,5,6,7
            bool right = true;  // 6,7,8,9

            for (int j = 2; j <= 5; j++) {
                if (s[j] == 1) {
                    left = false;
                    break;
                }
            }

            for (int j = 4; j <= 7; j++) {
                if (s[j] == 1) {
                    middle = false;
                    break;
                }
            }

            for (int j = 6; j <= 9; j++) {
                if (s[j] == 1) {
                    right = false;
                    break;
                }
            }

            // Left and right don't overlap
            if (left && right) {
                res += 2;
            }
            else if (left || middle || right) {
                res += 1;
            }
        }

        return res;
    }
};