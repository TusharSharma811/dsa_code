class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin() , intervals.end() , [](vector<int>& x , vector<int>& y){
            int x0 = x[0] , x1=x[1] , y0=y[0] , y1=y[1] ;
            return (x1==y1)?x0>y0 : x1<y1 ;
        });

        int count = 2 , n = intervals.size() ;
        int b= intervals[0][1] , a=b-1 ;

        for(int i=1 ; i<n   ; i++){
            int l = intervals[i][0] , r=intervals[i][1] ;
            if(a>=l)continue ;

            bool no = l>b ;
            count += 1+no ;
            a = no ? r-1 : b ;
            b=r ;
        }

        return count ;

    }
};