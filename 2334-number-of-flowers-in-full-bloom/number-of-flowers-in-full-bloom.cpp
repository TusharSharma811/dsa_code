class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        map<int , int > mpp ;
        int n = people.size() ;
           for(int p: people)
            mpp[p]=0;
        for(auto flowerRange : flowers){
            mpp[flowerRange[0]]++ ;
            mpp[flowerRange[1]+1]-- ;
        }
        vector<int> ans(n) ;
        int bloom = 0 ;
      for(auto& [p,bl]: mpp){
           bl+= bloom;
           bloom = bl;
       }
         for(int i= 0; i < n; i++){
           ans[i]= mpp[people[i]];
       }
       return ans;
    }
};