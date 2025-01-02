#include<iostream>
#include<bits/stdc++.h>
using namespace std ;
int main(){
int T ;
cin>>T ;
while(T--){
	int n ;
	cin>>n ;
	int min_elem = INT_MAX ;

	vector<int> arr(n) ;
	for(int i=0 ; i<n ; i++){
		cin>>arr[i] ;
		min_elem = min(min_elem , arr[i]) ;
	}

	if(arr[0] != min_elem){
		cout<<"NO"<<endl ;
	}
	else{
		cout<<"YES"<<endl ;
	}
	

}
return 0 ;
}