class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string curr;

        backtrack(ans, curr, 0, 0, n);

        return ans;
    }

    void backtrack(vector<string>& ans, string& curr,
                   int open, int close, int n) {

        if (curr.size() == 2 * n) {
            ans.push_back(curr);
            return;
        }

        if (open < n) {
            curr.push_back('(');
            backtrack(ans, curr, open + 1, close, n);
            curr.pop_back();
        }

        if (close < open) {
            curr.push_back(')');
            backtrack(ans, curr, open, close + 1, n);
            curr.pop_back();
        }
    }
};