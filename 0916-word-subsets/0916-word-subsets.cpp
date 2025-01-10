class Solution {
public:
    vector<int> countFreq(string& word) {
        vector<int> freq(26);
        for (auto& c : word)
            freq[c - 'a']++;
        return freq;
    }
    vector<string> wordSubsets(vector<string>& word1, vector<string>& word2) {
        vector<string> ans;

        vector<int> maxfreq(26);
        for (auto& word : word2) {
            vector<int> freq = countFreq(word);
            for(int i =0 ;i<26;i++) maxfreq[i] = max(maxfreq[i],freq[i]);
        }

        for(auto &word:word1){
            vector<int> freq = countFreq(word);
            int i = 0;
            for(;i<26;i++)
                if(freq[i]<maxfreq[i]) break;
            if(i == 26) ans.push_back(word);
        }
        return ans;
    }
};