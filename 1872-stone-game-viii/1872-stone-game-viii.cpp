class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();

        vector<long long> prefix(n);
        prefix[0] = stones[0];

        for (int i = 1; i < n; ++i) {
            prefix[i] = prefix[i - 1] + stones[i];
        }

        // At the end, all stones have been merged.
        long long ans = prefix[n - 1];

        // First move must take at least 2 stones,
        // so i starts from n - 2 down to 1.
        for (int i = n - 2; i >= 1; --i) {
            ans = max(ans, prefix[i] - ans);
        }

        return (int)ans;
    }
};