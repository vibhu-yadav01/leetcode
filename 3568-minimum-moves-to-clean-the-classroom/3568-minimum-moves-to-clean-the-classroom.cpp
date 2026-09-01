class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        int sr = -1, sc = -1;
        vector<pair<int, int>> litter;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                } else if (classroom[i][j] == 'L') {
                    litter.push_back({i, j});
                }
            }
        }

        int k = litter.size();
        if (k == 0) return 0;

        vector<vector<int>> id(m, vector<int>(n, -1));
        for (int i = 0; i < k; ++i) {
            id[litter[i].first][litter[i].second] = i;
        }

        int fullMask = (1 << k) - 1;

        // State: row, col, remaining energy, collected litter mask
        struct State {
            int r, c, e, mask, dist;
        };

        queue<State> q;

        // visited[r][c][energy][mask]
        vector<vector<vector<vector<bool>>>> visited(
            m, vector<vector<vector<bool>>>(
                n, vector<vector<bool>>(
                    energy + 1, vector<bool>(1 << k, false)
                )
            )
        );

        visited[sr][sc][energy][0] = true;
        q.push({sr, sc, energy, 0, 0});

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {
            auto [r, c, e, mask, dist] = q.front();
            q.pop();

            if (mask == fullMask)
                return dist;

            for (int d = 0; d < 4; ++d) {
                int nr = r + dr[d];
                int nc = c + dc[d];

                if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                    continue;

                if (classroom[nr][nc] == 'X')
                    continue;

                // Need one unit of energy to make the move.
                if (e == 0)
                    continue;

                int ne = e - 1;
                int nmask = mask;

                // Collect litter.
                if (classroom[nr][nc] == 'L') {
                    nmask |= (1 << id[nr][nc]);
                }

                // Reset energy immediately upon reaching R.
                if (classroom[nr][nc] == 'R') {
                    ne = energy;
                }

                if (!visited[nr][nc][ne][nmask]) {
                    visited[nr][nc][ne][nmask] = true;
                    q.push({nr, nc, ne, nmask, dist + 1});
                }
            }
        }

        return -1;
    }
};