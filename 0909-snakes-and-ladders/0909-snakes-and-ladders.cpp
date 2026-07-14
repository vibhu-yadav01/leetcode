class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        int target = n * n;

        queue<pair<int, int>> q;
        vector<bool> visited(target + 1, false);

        q.push({1, 0});
        visited[1] = true;

        while (!q.empty()) {
            int curr = q.front().first;
            int moves = q.front().second;
            q.pop();

            if (curr == target) {
                return moves;
            }

            for (int next = curr + 1;
                 next <= min(curr + 6, target);
                 next++) {

                int row = (next - 1) / n;
                int col = (next - 1) % n;

                int boardRow = n - 1 - row;

                if (row % 2 == 1) {
                    col = n - 1 - col;
                }

                int destination = next;

                if (board[boardRow][col] != -1) {
                    destination = board[boardRow][col];
                }

                if (!visited[destination]) {
                    visited[destination] = true;
                    q.push({destination, moves + 1});
                }
            }
        }

        return -1;
    }
};