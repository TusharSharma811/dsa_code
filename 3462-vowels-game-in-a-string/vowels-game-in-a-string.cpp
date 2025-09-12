class Solution {
public:
    bool doesAliceWin(string s) {
        string vows = "aeiou" ;
        int count = 0 ;
        for(auto ch : s){
            if(vows.find(ch) != string::npos){
                return true ;
            }
        }
        return false ;
    }
};