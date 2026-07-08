class Solution {
public:
    static const int MOD = 1000000007;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();

        vector<long long> prefSum(n + 1, 0);
        for (int i = 0; i < n; i++)
            prefSum[i + 1] = prefSum[i] + (s[i] - '0');

        vector<int> pos;
        vector<int> digit;

        for (int i = 0; i < n; i++) {
            if (s[i] != '0') {
                pos.push_back(i);
                digit.push_back(s[i] - '0');
            }
        }

        int k = digit.size();

        vector<long long> pow10(k + 1, 1);
        for (int i = 1; i <= k; i++)
            pow10[i] = (pow10[i - 1] * 10) % MOD;

        vector<long long> hash(k + 1, 0);
        for (int i = 1; i <= k; i++)
            hash[i] = (hash[i - 1] * 10 + digit[i - 1]) % MOD;

        vector<int> ans;

        for (auto &q : queries) {
            int l = q[0], r = q[1];

            long long sum = prefSum[r + 1] - prefSum[l];

            auto itL = lower_bound(pos.begin(), pos.end(), l);
            auto itR = upper_bound(pos.begin(), pos.end(), r);

            if (itL == itR) {
                ans.push_back(0);
                continue;
            }

            int L = (itL - pos.begin()) + 1;
            int R = (itR - pos.begin());
            int len = R - L + 1;

            long long x = (hash[R] - hash[L - 1] * pow10[len]) % MOD;
            if (x < 0) x += MOD;

            ans.push_back((x * (sum % MOD)) % MOD);
        }

        return ans;
    }
};