class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char, int> freq ;
        string vow = "aeiou" ;
        int maxVowFreq = 0 , maxConstFreq = 0 ;


        for(char ch : s){
            freq[ch]++ ;
        }


        for(auto [key , val ] : freq){
            if(vow.find(key) != string::npos){
                maxVowFreq = max(maxVowFreq , val) ;
            }
            else{
                maxConstFreq = max(maxConstFreq , val) ;
            }
        }

        return maxVowFreq + maxConstFreq ;
    }
};