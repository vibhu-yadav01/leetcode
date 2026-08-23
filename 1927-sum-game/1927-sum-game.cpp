class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int mid = n / 2;

        int leftSum = 0, rightSum = 0;
        int leftQ = 0, rightQ = 0;

        for (int i = 0; i < mid; ++i) {
            if (num[i] == '?')
                ++leftQ;
            else
                leftSum += num[i] - '0';
        }

        for (int i = mid; i < n; ++i) {
            if (num[i] == '?')
                ++rightQ;
            else
                rightSum += num[i] - '0';
        }

        // Bob can win only if the maximum possible adjustment
        // can exactly compensate for the current difference.
        return 2 * (leftSum - rightSum) !=
               9 * (rightQ - leftQ);
    }
};