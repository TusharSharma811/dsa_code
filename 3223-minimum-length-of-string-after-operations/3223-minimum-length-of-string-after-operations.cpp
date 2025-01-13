class Solution {
public:
    int minimumLength(string s) {
        
        
        vector<int> chars(26,0);

        for(auto c : s)
        {
            chars[c-'a']++;
        }

        int minLen = 0 ;

        for(int i = 0;i<26;i++)
        {
            if(chars[i]==0) continue;
            
            chars[i]%2==0 ? minLen+=2 : minLen+=1;
            
        }
        return minLen;
    }
};