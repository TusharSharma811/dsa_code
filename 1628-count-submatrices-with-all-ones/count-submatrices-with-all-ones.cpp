class Solution {
public:
     int OnedArrayCount(vector<int>& vec) {
        int cons = 0;
        int subCount = 0;

        for(int &val : vec) {
            if(val == 0) {
                cons = 0;
            } else {
                cons++;
            }

            subCount += cons;
        }

        return subCount;
    }
    int numSubmat(vector<vector<int>>& mat) {
        int n = mat.size() ;
        int m = mat[0].size() ;


        int result = 0 ;

        for(int start =0 ; start<n ; start++){
            vector<int> temp(m , 1) ;
            for(int end = start ; end<n ; end++){
                for(int col= 0 ; col<m ; col++){
                    temp[col] = temp[col]&mat[end][col] ;
                }

                result += OnedArrayCount(temp);

            }
        }
        return result ; 
    }
};