class Solution {
public:

    bool checkInPoints(int i , int j , vector<vector<int>> points){
        for(int k=0 ; k<points.size() ; k++){
            if(k==i || k==j)continue ;
            int x = points[k][0] ;
            int y = points[k][1] ;
            if((x >= points[i][0] && x<=points[j][0] ) && (y<=points[i][1] && y>= points[j][1])){
                return false ; 
            }
            
        }
        return true ;
    }


    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size() ;
        int ans = 0 ;
        for(int i=0 ; i<n ; i++){
             int xA = points[i][0] ;
              int yA = points[i][1] ;
            for(int j=0 ; j <n ; j++ ){
                if(i==j)continue ;
                int xB = points[j][0] ;
                int yB = points[j][1] ;

                if(yA >= yB && xA <= xB && checkInPoints(i , j , points)){
                    ans++ ;
                }
            }
        }

        return ans ; 
    }
};