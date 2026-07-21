class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        string t = "1" + s + "1";
        int initialOnes = 0;
        for (char c : s) initialOnes += (c == '1');

        // Run-length encoding of t
        vector<pair<char, int>> runs;
        for (int i = 0; i < (int)t.size();) {
            int j = i;
            while (j < (int)t.size() && t[j] == t[i]) j++;
            runs.push_back({t[i], j - i});
            i = j;
        }

        int m = runs.size();

        // prefix/suffix maximum zero-run length
        vector<int> pref(m, 0), suff(m, 0);
        for (int i = 0; i < m; i++) {
            pref[i] = (i ? pref[i - 1] : 0);
            if (runs[i].first == '0')
                pref[i] = max(pref[i], runs[i].second);
        }
        for (int i = m - 1; i >= 0; i--) {
            suff[i] = (i + 1 < m ? suff[i + 1] : 0);
            if (runs[i].first == '0')
                suff[i] = max(suff[i], runs[i].second);
        }

        int ans = initialOnes;

        // Try removing every removable 1-run
        for (int i = 1; i + 1 < m; i++) {
            if (runs[i].first != '1') continue;

            int leftZero = runs[i - 1].second;
            int rightZero = runs[i + 1].second;
            int oneLen = runs[i].second;

            int mergedZero = leftZero + oneLen + rightZero;

            int otherMaxZero = 0;
            if (i - 2 >= 0) otherMaxZero = max(otherMaxZero, pref[i - 2]);
            if (i + 2 < m) otherMaxZero = max(otherMaxZero, suff[i + 2]);

            int bestZeroToFlip = max(mergedZero, otherMaxZero);

            ans = max(ans, initialOnes - oneLen + bestZeroToFlip);
        }

        return ans;
    }
};