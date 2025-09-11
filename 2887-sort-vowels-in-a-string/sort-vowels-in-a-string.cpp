class Solution {
public:
    string sortVowels(string s) {
        auto isVowel = [&](char x){
            return string("AEIOUaeiou").find(x) != string::npos ;
        };
      vector<char> vowels;
        for (char c : s) {
            if (isVowel(c)) {
                vowels.push_back(c);
            }
        }

        sort(vowels.begin(), vowels.end());

        

        int v_index = 0;
        for (int i = 0; i < s.size(); i++) {
            if (isVowel(s[i])) {
                s[i] = vowels[v_index++];
            }
        }

        return s;


    }
};