class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> matrix(n ,  vector<int>(n, 0)) ;
        for(auto query : queries){
            int top = query[0] ;
            int left = query[1] ;
            int bottom = query[2] ;
            int right = query[3] ;

            for(int i=top ; i<=bottom ; i++){
                for(int j=left ; j<=right ; j++){
                    matrix[i][j]++ ;
                }
            }
        }

        return matrix ;
    }
};