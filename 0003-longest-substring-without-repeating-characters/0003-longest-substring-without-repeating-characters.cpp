class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> m; // character idx
        int ans =0;
        int i=0; //left pointer

        for(int j=0; j<s.size(); j++){ //j is the right part
            char ch = s[j];

            if(m.count(ch) && m[ch] >= i){
                i = m[ch] +1;
            }

            m[ch] = j;

            ans = max(ans, j-i+1);
        }
        return ans;
    }
};