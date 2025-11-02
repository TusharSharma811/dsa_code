class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
          vector<vector<int>> grid(m, vector<int>(n, 0));
           for (auto& g : guards) {
            grid[g[0]][g[1]] = -1;
        }
         for (auto& w : walls) {
            grid[w[0]][w[1]] = -2;
        }
        vector<pair<int,int>> directions = {{1,0}, {0,1}, {-1,0}, {0,-1}};

         for (auto& g : guards) {
            int r = g[0], c = g[1];
            
            for (auto& d : directions) {
                int dr = d.first, dc = d.second;
                int nr = r + dr, nc = c + dc;
                
                while (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    if (grid[nr][nc] == -1 || grid[nr][nc] == -2) break;
                    if (grid[nr][nc] == 0) grid[nr][nc] = 1;
                    
                    nr += dr;
                    nc += dc;
                }
            }
        }
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) count++;
            }
        }
        
        return count;
        
    }
};