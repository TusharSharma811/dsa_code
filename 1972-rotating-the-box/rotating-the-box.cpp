class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int n = box.size();
        int m = box[0].size();
       
        for (int i = 0; i < n; i++) {
            for (int j = m - 1; j >= 0; j--) {
                if (box[i][j] == '*' || box[i][j] == '.') continue;
                else {
                    int a = j + 1;
                    while (a < m && box[i][a] == '.') {
                        a++;
                    }
                    swap(box[i][j], box[i][a - 1]); 
                }
            }
        }
        
    
        vector<vector<char>> ans(m, vector<char>(n, '.'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans[j][n - 1 - i] = box[i][j];
            }
        }
        
        return ans;
    }
};