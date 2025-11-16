class Solution {
public:
    int numSub(string s) {
        long long int currOne = 0 ;
        long long int result = 0 ;
        int mod = 1e9 + 7 ;
        for(int i=0 ; i<s.length() ; i++){
            if(s[i] == '0'){
                currOne = 0 ;
                continue ;
            }
            else{
                currOne++ ;
                result += currOne ;
            }
        }

        return result%mod ;
    }
};