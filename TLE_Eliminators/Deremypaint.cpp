#include<iostream>
#include<bits/stdc++.h>
using namespace std ;
int main(){
int T ;
cin>>T ;
while(T--){
	int n ;
	cin >> n ;
	vector<int> arr(n) ;
	unordered_map<int , int> mpp ;
	
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i] ;
		mpp[arr[i]]++ ;
		
	}
  if(mpp.size() == 1){
  	cout<<"Yes"<<endl ;
  }
 else if(mpp.size() == 2){
		
			auto it = mpp.begin() ;
			int count1 = it->second ;
			++it ;
			int count2 = it->second ;

			if(abs(count1 - count2) <= 1 ){
				cout<<"Yes"<<endl ;
			}
			else{
				cout<<"No"<<endl ;
			}
		
	}
	else{
		cout<<"No"<<endl ;
	}

}
return 0 ;
}