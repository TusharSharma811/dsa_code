#include<iostream>
using namespace std ;

int main(){
    int t ;
    cin>>t ;
    while(t--){
        int n ;
        cin>>n ;
        string s ;
        cin>>s ;
        int ans =0 ;
        if(s[0] == '.')ans++ ;
        for(int i=1 ; i<s.length() ; i++){
            if(s[i-1] == '.' && s[i+1] == '.' && s[i]=='.' ){
                cout<<2<<endl ;
                ans = -1 ;
                break ;
                
            }
            if(s[i] == '.'){
                ans++ ;
            }
        }
        if(ans >= 0)cout<<ans<<endl ;
    }
 return 0 ;
}