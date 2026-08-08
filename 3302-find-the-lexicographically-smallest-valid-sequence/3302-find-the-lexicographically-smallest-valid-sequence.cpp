class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
         int n = word1.size();
        int m = word2.size();

        vector<int> ans(m);

        // last[j] = position selected for word2[j] when we
        // greedily match word2[j..m-1] from right to left.
        vector<int> last(m, -1);

        int i = n - 1;
        int j = m - 1;

        // Build a rightmost exact subsequence of word2 in word1.
        while (i >= 0 && j >= 0) {
            if (word1[i] == word2[j]) {
                last[j] = i;
                --j;
            }
            --i;
        }

        // We can use at most one mismatch.
        bool canMismatch = true;

        j = 0;

        for (i = 0; i < n && j < m; ++i) {
            // Best case: exact match.
            if (word1[i] == word2[j]) {
                ans[j++] = i;
            }
            // Use the one mismatch here, but only if the rest
            // can be matched exactly after i.
            else if (canMismatch &&
                     (j == m - 1 || i < last[j + 1])) {
                ans[j++] = i;
                canMismatch = false;
            }
        }

        // We couldn't construct a sequence of length m.
        if (j != m)
            return {};

        return ans;
    }
};