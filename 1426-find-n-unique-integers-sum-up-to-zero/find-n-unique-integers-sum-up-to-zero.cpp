class Solution {
public:
    vector<int> sumZero(int n) {
        bool flag = false ;
        vector<int> vec(n,0) ;
        int i=1 ;
        int num = 1 ;
        if(n%2 == 0 ){
            i=0 ;
        }
        for(; i<n-1 ; i +=2 ){
            vec[i] = num ;
            vec[i+1] = -num ;
            num++ ;
        }
        return vec ;
    }
};