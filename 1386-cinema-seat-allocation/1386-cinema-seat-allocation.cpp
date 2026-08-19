class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
            unordered_map<int, int> reserved;

        for (auto &seat : reservedSeats) {
            int row = seat[0];
            int s = seat[1];

            if (s >= 2 && s <= 9) {
                reserved[row] |= (1 << (s - 2));
            }
        }

        // Masks for:
        // 2,3,4,5 -> 00001111
        // 4,5,6,7 -> 00111100
        // 6,7,8,9 -> 11110000
        const int LEFT  = 0b00001111;
        const int MIDDLE = 0b00111100;
        const int RIGHT = 0b11110000;

        int ans = 2 * (n - reserved.size());

        for (auto &[row, mask] : reserved) {
            bool left = (mask & LEFT) == 0;
            bool right = (mask & RIGHT) == 0;

            if (left && right) {
                // Seats 2-5 and 6-9 can both be used.
                ans += 2;
            } else if (left || right || (mask & MIDDLE) == 0) {
                // At least one valid block is available.
                ans += 1;
            }
        }

        return ans;    
    }
};