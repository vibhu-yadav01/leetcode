class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        queue<pair<int, int>> q;

        auto add = [&](int r, int c) {
            if (r >= 0 && r < m && c >= 0 && c < n && board[r][c] == 'O') {
                board[r][c] = '#';   // Mark as safe
                q.push({r, c});
            }
        };

        // Add all border O's
        for (int i = 0; i < m; i++) {
            add(i, 0);
            add(i, n - 1);
        }

        for (int j = 0; j < n; j++) {
            add(0, j);
            add(m - 1, j);
        }

        // BFS from border O's
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr >= 0 && nr < m && nc >= 0 && nc < n &&
                    board[nr][nc] == 'O') {
                    board[nr][nc] = '#';
                    q.push({nr, nc});
                }
            }
        }

        // Capture surrounded regions and restore safe regions
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == '#')
                    board[i][j] = 'O';
            }
        }
    }
};