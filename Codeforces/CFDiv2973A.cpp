#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int main(){
    int T ;
    cin >> T ;
    while(T--){
        int x , y , n ,ans =0  ;
        cin>>n ;
        cin>>x>>y ;
        if(n==0){
            cout<<0<<endl ;
            continue ;
        }
        while(n > 0){
            n = n-(min(x , n)) ;
            ans++ ;
        }
        cout<<ans<<endl ;

    }
    return 0 ;
}