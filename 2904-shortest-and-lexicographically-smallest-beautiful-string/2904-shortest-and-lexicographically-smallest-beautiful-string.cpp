class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();

        vector<int> pos;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1')
                pos.push_back(i);
        }

        if (pos.size() < k)
            return "";

        int bestLen = INT_MAX;
        string ans = "";

        for (int i = 0; i + k - 1 < (int)pos.size(); i++) {
            int first = pos[i];
            int last = pos[i + k - 1];

            // To contain exactly these k ones:
            // start can be from the position after the previous 1
            // up to the first 1.
            int left = (i == 0 ? 0 : pos[i - 1] + 1);

            // For the shortest length, start as far right as possible.
            int start = first;
            int len = last - start + 1;

            if (len < bestLen) {
                bestLen = len;
                ans = s.substr(start, len);
            } 
            else if (len == bestLen) {
                string cur = s.substr(start, len);
                if (cur < ans)
                    ans = cur;
            }
        }

        return ans;
    }
};