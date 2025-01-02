#include<iostream>
#include<bits/stdc++.h>
using namespace std ;
int main(){
int T ;
cin>>T ;
while(T--){
	int n , m ;
	cin>>n>>m ;
	string x , s ;
	cin>>x ;
	cin>>s ;
	int operations = 0 ;
	bool flag = false ;
	int count= 6 ;
	while(count--){
		if(x.find(s) != string::npos){
			cout<<operations<<endl ;
			flag = true ;
			break ;
		}
		x = x + x ;
		operations++ ;
	}
	if(!flag){
		cout<<-1<<endl ;
	}
	
}
return 0 ;
}