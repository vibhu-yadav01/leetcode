class Solution {
public:
    int maximumLengthSubstring(string s) {
       unordered_map<char, int> freq;
        int left = 0, ans = 0;

        for (int right = 0; right < s.size(); right++) {
            freq[s[right]]++;

            // Make sure every character occurs at most twice
            while (freq[s[right]] > 2) {
                freq[s[left]]--;
                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans; 
    }
};