class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<bool> visited(n, false);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (visited[i]) continue;

            int vertices = 0;
            int degreeSum = 0;

            queue<int> q;
            q.push(i);
            visited[i] = true;

            while (!q.empty()) {
                int node = q.front();
                q.pop();

                vertices++;
                degreeSum += adj[node].size();

                for (int nei : adj[node]) {
                    if (!visited[nei]) {
                        visited[nei] = true;
                        q.push(nei);
                    }
                }
            }

            // Complete graph with k vertices has k * (k - 1) / 2 edges.
            // degreeSum counts every edge twice.
            if (degreeSum == vertices * (vertices - 1))
                ans++;
        }

        return ans;
    }
};