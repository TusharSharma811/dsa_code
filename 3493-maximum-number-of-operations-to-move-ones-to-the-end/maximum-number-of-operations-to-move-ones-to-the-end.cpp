class Solution {
public:
    int maxOperations(string s) {
        int cnt1 = 0 ;
        int n = s.length() ;
        int ans = 0 ;
        for(int i=0  ; i<n-1 ; i++){
            if(s[i]=='1'){
                cnt1++ ;
                if(s[i+1] == '0'){
                    ans+=cnt1 ;
                }
            }
            
        }
        return ans ;
    }


};