class Solution {
public:
    int minSwaps(string s) {
        int n = s.size() ;
        int oneCount = 0 , zeroCount = 0  ;

        for(auto ch : s){
            if(ch == '1'){
                oneCount++ ;
            }
            else{
                zeroCount++ ;
            }
        }

        if(abs(zeroCount - oneCount) >= 2)return -1 ;
       
        int miss0 = 0, miss1 = 0;
        for(int i = 0; i < n; i += 2){
            if(s[i] == '0') ++miss1;
            else ++miss0;
        }
        return oneCount == zeroCount ? min(miss0 , miss1) : (oneCount > zeroCount ? miss1 : miss0);
       
       
    }
};