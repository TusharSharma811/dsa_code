#include<bits/stdc++.h>
#include<iostream>

using namespace std ;
int main(){
int T ;
cin>>T ;
while(T--){
    int n ;
    cin>>n ;
    if((n+1)%3 == 0 || (n-1)%3 == 0 ){
    	cout<<"First"<<endl ;
    }
    else{
    	cout<<"Second"<<endl ;
    }
}
return 0 ;
}