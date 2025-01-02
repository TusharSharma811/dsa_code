#include<iostream>
#include<bits/stdc++.h>
#include <fstream>
using namespace std ;

int main(){
    int T  ;
    cin>>T ;
    ofstream file("output2.txt");
    for(int i=0 ; i<T ; i++){
        unordered_map<double , int> mpp ;
        int n ; 
        int maxslope = INT_MIN ;
        double slope ;
        cin>>n ;
        vector<int> xcord(n) ;
         vector<int> ycord(n) ;

         for(int k=0 ; k<n ; k++){
            cin >> xcord[k] >> ycord[k];
         }
         for(int j=0 ; j<n ; j++){
            for(int l=j+1 ; l<n ; l++){
                if (xcord[l] - xcord[j] == 0) {
                    continue ;
                }
                else{
                     slope = abs(double((ycord[l] - ycord[j]) / (xcord[l]-xcord[j]))) ;
                    
                }
                
                if(mpp.find(slope) != mpp.end()){
                    mpp[slope]++ ;
                }
                else{
                    mpp[slope] = 1 ;
                }

            }
         }
         for( auto m:mpp){
           
            maxslope = max(maxslope , m.second) ;
             cout<<"slope is : "<<m.first<<" "<<maxslope<<endl ;
         }
         int ans = n - ((maxslope/2)+1 );
      file<<"Case #"<<i+1<<":"<<ans<<endl ;

    }
    return 0 ;
}