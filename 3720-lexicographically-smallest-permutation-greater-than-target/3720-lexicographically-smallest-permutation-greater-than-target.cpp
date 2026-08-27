class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();
        vector<int> cnt(26, 0);

        for (char ch : s)
            cnt[ch - 'a']++;

        // Match target from left to right.
        for (int i = 0; i < n; ++i) {
            int cur = target[i] - 'a';

            if (cnt[cur] > 0) {
                cnt[cur]--;
                continue;
            }

            // Current character cannot match.
            // First, try to make THIS position larger.
            for (int c = cur + 1; c < 26; ++c) {
                if (cnt[c] == 0)
                    continue;

                string ans = target.substr(0, i);
                ans += char('a' + c);
                cnt[c]--;

                // Smallest possible suffix.
                for (int k = 0; k < 26; ++k)
                    ans.append(cnt[k], char('a' + k));

                return ans;
            }

            // Can't increase current position.
            // Backtrack to the rightmost previous position.
            for (int j = i - 1; j >= 0; --j) {
                // Put target[j] back into the available characters.
                cnt[target[j] - 'a']++;

                int prev = target[j] - 'a';

                // Increase target[j] by the smallest possible amount.
                for (int c = prev + 1; c < 26; ++c) {
                    if (cnt[c] == 0)
                        continue;

                    string ans = target.substr(0, j);
                    ans += char('a' + c);
                    cnt[c]--;

                    // Smallest possible suffix.
                    for (int k = 0; k < 26; ++k)
                        ans.append(cnt[k], char('a' + k));

                    return ans;
                }
            }

            return "";
        }

        // target itself is a permutation of s.
        // Find its next greater permutation.
        for (int i = n - 1; i >= 0; --i) {
            cnt[target[i] - 'a']++;

            int cur = target[i] - 'a';

            for (int c = cur + 1; c < 26; ++c) {
                if (cnt[c] == 0)
                    continue;

                string ans = target.substr(0, i);
                ans += char('a' + c);
                cnt[c]--;

                for (int k = 0; k < 26; ++k)
                    ans.append(cnt[k], char('a' + k));

                return ans;
            }
        }

        return "";
    }
};