#include<iostream>
#include<bits/stdc++.h>
#include <fstream>
using namespace std ;

int main(){
    int T , L=1 ;
    cin>>T ;
    ofstream file("output.txt");
    while(L<=T){
        int n ;
        long long int k ;
        cin>>n>>k ;
        vector<int> arr(n) ;
        for(int i=0 ; i<n ; i++){
            cin>>arr[i] ;
        }
        if(n==1){
            if(arr[0] <= k ) {
                   file<<"Case #"<<L<<":"<<" YES"<<endl ;
            }
            else{
                file<<"Case #"<<L<<":"<<" NO"<<endl ;
            }
            L++ ;
            continue;
        }
        sort(arr.begin() , arr.end()) ;
        int start = 0 , end = n-1 ;
        long long int ans = 0 ;
        
        while(start<end){
            if(end > start+1){
                ans = ans + 2*(arr[start]) ;
                end-- ;
            }
            else{
                ans = ans+arr[start] ;
                end-- ;
            }
        }
        if(ans <= k && ans != 0){
            file<<"Case #"<<L<<":"<<" YES"<<endl ;
        }
        else{
           file<<"Case #"<<L<<":"<<" NO"<<endl ;
        }
        L++ ;
    }
    return 0 ;
}