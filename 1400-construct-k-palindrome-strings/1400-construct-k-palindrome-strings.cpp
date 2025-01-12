class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.length()==k){
            return true;
        }
        if(s.length()<k){
            return false;
        }
        vector<int> v(26,0);
        for(char c : s){
            v[c-'a']++;
        }
        int count = 0;
        for(int i : v){
            if(i%2==1){
                count++;
            }
        }
        if(count<=k){
            return true;
        }
        return false;
    }
};