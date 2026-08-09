class Solution {
public:
    vector<vector<int>> memo;
    vector<int> suffix;
    int n;

    int solve(int i, int M) {
        // All remaining stones can be taken.
        if (i >= n)
            return 0;

        if (2 * M >= n - i)
            return suffix[i];

        if (memo[i][M] != -1)
            return memo[i][M];

        int best = 0;

        // Take X piles, where 1 <= X <= 2M
        for (int X = 1; X <= 2 * M && i + X <= n; X++) {
            // Stones remaining after taking X piles:
            // suffix[i + X]
            //
            // solve(i + X, max(M, X)) is the maximum
            // the opponent can obtain from those remaining piles.
            int opponent = solve(i + X, max(M, X));

            int current = suffix[i] - opponent;
            best = max(best, current);
        }

        return memo[i][M] = best;
    }

    int stoneGameII(vector<int>& piles) {
        n = piles.size();

        // suffix[i] = total stones from i to n-1
        suffix.assign(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            suffix[i] = suffix[i + 1] + piles[i];
        }

        // M can grow up to n.
        memo.assign(n, vector<int>(n + 1, -1));

        return solve(0, 1);
    }
};