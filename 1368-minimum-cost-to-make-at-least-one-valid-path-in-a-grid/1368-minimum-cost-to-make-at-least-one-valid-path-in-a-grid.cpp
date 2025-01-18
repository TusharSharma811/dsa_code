class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> moves = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        deque<array<int, 3>> queue;
        unordered_map<string, int> visited;
        
        queue.push_front({0, 0, 0});
        visited["0,0"] = 0;

        while (!queue.empty()) {
            auto [r, c, cost] = queue.front();
            queue.pop_front();

            if (r == n - 1 && c == m - 1) return cost;

            for (int move = 1; move <= 4; move++) {
                int x = moves[move - 1][0], y = moves[move - 1][1];
                int newR = r + x, newC = c + y;
                int newCost = cost + (grid[r][c] == move ? 0 : 1);
                
                string key = to_string(newR) + "," + to_string(newC);
                if (newR >= 0 && newR < n && newC >= 0 && newC < m 
                    && (visited.find(key) == visited.end() || newCost < visited[key])) {
                    visited[key] = newCost;
                    if (grid[r][c] == move) {
                        queue.push_front({newR, newC, newCost});
                    } else {
                        queue.push_back({newR, newC, newCost});
                    }
                }
            }
        }
        
        return -1; // Should not reach here
    }
};
