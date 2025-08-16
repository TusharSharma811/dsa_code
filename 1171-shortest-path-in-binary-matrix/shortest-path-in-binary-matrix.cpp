class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int n = grid.size();
        int m = grid[0].size();

        if (grid[0][0] != 0 || grid[n - 1][n - 1] != 0)
            return -1;

        vector<vector<bool>> visited(n, vector<bool>(m, false));
        vector<vector<int>> dist(n, vector<int>(m, 0));
        dist[0][0] = 1;
        q.push({0, 0});

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            if (r == n - 1 && c == n - 1)
                return dist[r][c];

            for (int dr = -1; dr <= 1; dr++) {
                for (int dc = -1; dc <= 1; dc++) {
                    if (dr == 0 && dc == 0)
                        continue;

                    int nr = r + dr;
                    int nc = c + dc;

                    if (nc >= 0 && nc < n && nr >= 0 && nr < n &&
                        !visited[nr][nc] && grid[nr][nc] == 0) {
                        visited[nr][nc] = true;
                        dist[nr][nc] = dist[r][c] + 1;
                        q.push({nr, nc});
                    }
                }
            }
        }

        return -1;
    }
};