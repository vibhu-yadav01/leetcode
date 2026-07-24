class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end());

        // Smallest power of 2 greater than mx
        int LIM = 1;
        while (LIM <= mx) LIM <<= 1;

        vector<bool> pairXor(LIM, false);
        vector<bool> ans(LIM, false);

        int n = nums.size();

        // All XORs of pairs (i <= j)
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                pairXor[nums[i] ^ nums[j]] = true;
            }
        }

        // Add the third element
        for (int x = 0; x < LIM; x++) {
            if (!pairXor[x]) continue;
            for (int v : nums) {
                ans[x ^ v] = true;
            }
        }

        return count(ans.begin(), ans.end(), true);
    }
};