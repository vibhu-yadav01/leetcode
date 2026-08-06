class Solution {
public:
    int smallestNumber(int n, int t) {
         for (int x = n;; x++) {
            int prod = 1;
            int y = x;

            if (y == 0) prod = 0;
            while (y > 0) {
                prod *= (y % 10);
                y /= 10;
                if (prod == 0) break; // once product is 0, it stays 0
            }

            if (prod % t == 0)
                return x;
         }
    }
};