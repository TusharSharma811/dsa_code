#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int main(){
    int T ;
    cin >> T ;
    while(T--){
        int n ;
        cin >> n ;
      vector<long long> v(n) ;
      for(int i=0 ; i<n ;i++){
          cin >> v[i] ;
      }
      sort(v.begin() , v.end()) ;
      long long int max_rating = v[n-1] ;
      long long sum = 0 ;
     for(int i=0 ; i<n-2 ; i++){
        sum = sum + v[i] ;
     }
     long long secondbest = v[n-2] - sum ;
     cout<<max_rating-secondbest<<endl ;

    }
    return 0 ;
}