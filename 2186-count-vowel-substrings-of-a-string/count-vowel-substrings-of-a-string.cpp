class Solution {
public:
    bool isVowel(char ch){
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ;
    }

    int solve(string& word , int start , int end){
        unordered_map<char , int > mp ;
        int cnt = 0 ; 
        for(int i=start ; i<=end ; i++){
            mp[word[i]]++ ;
            if(mp.size() == 5){
                int k = start ;
                while(mp.size() == 5){
                    --mp[word[k]] ;
                    if(mp[word[k]] == 0){
                        mp.erase(word[k]) ;
                        break ;
                    }
                    k++ ;
                }

                int prefix = k-start+1 ;
                int suffix = end-i+1 ;
                cnt += (prefix * suffix) ;
                start = k+1 ; 
            }
        }

        return cnt ;
    }
    int countVowelSubstrings(string word) {
        int sz = word.size() ;
        int ans = 0 ; 
        for(int i=0 ; i<sz ; i++){
            if(isVowel(word[i])){
                int j = i+1 ;
                while(j<sz && isVowel(word[j]))j++ ;
                ans += solve(word , i , j-1 ) ;
                i=j ; 
            }
        }
        return ans ;
    }
};