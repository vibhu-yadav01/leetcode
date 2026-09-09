class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;
        long long power = 1000;
        long long commas = 1;

        while (power <= n) {
            long long end = min(n, power * 1000 - 1);

            ans += (end - power + 1) * commas;

            power *= 1000;
            commas++;
        }

        return ans;
    }
};