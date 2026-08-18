class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
         int n = nums.size();
        unordered_map<int, int> freq;

        // For each subarray of size k, count each distinct element once.
        for (int i = 0; i + k <= n; ++i) {
            unordered_set<int> seen;

            for (int j = i; j < i + k; ++j) {
                seen.insert(nums[j]);
            }

            for (int x : seen) {
                freq[x]++;
            }
        }

        int ans = -1;

        for (auto& [x, count] : freq) {
            if (count == 1) {
                ans = max(ans, x);
            }
        }

        return ans;
    }
};