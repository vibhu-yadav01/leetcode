class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
    unordered_set<string> valid(bank.begin(), bank.end());

        if (!valid.count(endGene))
            return -1;

        queue<pair<string, int>> q;
        q.push({startGene, 0});

        unordered_set<string> visited;
        visited.insert(startGene);

        vector<char> genes = {'A', 'C', 'G', 'T'};

        while (!q.empty()) {
            auto [curr, steps] = q.front();
            q.pop();

            if (curr == endGene)
                return steps;

            string temp = curr;

            for (int i = 0; i < 8; i++) {
                char original = temp[i];

                for (char ch : genes) {
                    if (ch == original)
                        continue;

                    temp[i] = ch;

                    if (valid.count(temp) && !visited.count(temp)) {
                        visited.insert(temp);
                        q.push({temp, steps + 1});
                    }
                }

                temp[i] = original;
            }
        }

        return -1;
    }
};