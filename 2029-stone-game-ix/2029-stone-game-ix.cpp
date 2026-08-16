class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int cnt[3] = {};

        for (int x : stones)
            cnt[x % 3]++;

        auto check = [&](int zero, int one, int two) -> bool {
            // Alice starts by taking a remainder-1 stone.
            if (one == 0)
                return false;

            one--;

            // Then the forced sequence is:
            // 1, 2, 1, 2, ...
            int len = 1 + min(one, two) * 2 + zero;

            // If there are extra 1's, one more 1 can be taken.
            if (one > two) {
                one--;
                len++;
            }

            // Alice wins if:
            // 1. The number of effective moves is odd.
            // 2. There are still stones remaining.
            return (len % 2 == 1) && (one != two);
        };

        // Try Alice taking remainder 1 first,
        // or remainder 2 first.
        return check(cnt[0], cnt[1], cnt[2]) ||
               check(cnt[0], cnt[2], cnt[1]);
    }
};