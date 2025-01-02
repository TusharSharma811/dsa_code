
    #include <iostream>
    #include<bits/stdc++.h>
    #include <cmath>
    #include <iomanip>
    #include<limits>
    #include<fstream>
    using namespace std ;

    int main() {
        int T;
         ifstream inpfile("inputfile.txt") ;
        inpfile >> T;
         ofstream file("output3.txt");
        
        for (int i = 0; i < T; ++i) {
            int n ;
            inpfile>>n ;
            vector<int> a(n) ;
            vector<int> b(n) ;
            for(int i=0 ; i<n ; i++){
                inpfile>>a[i] ;
                inpfile>>b[i] ;
            }

            double v_min = 0.0 ;
            double v_max = numeric_limits<double>::infinity() ;
        
            for(int i=1 ; i<=n ; i++){
                double v_min_i = static_cast<double>(i) / b[i-1] ;
                double v_max_i = static_cast<double>(i) / a[i-1] ;
                v_min = max(v_min , v_min_i) ;
                v_max = min(v_max , v_max_i) ;
                if(v_min > v_max){
                    break ;
                }
            }
            if(v_min > v_max){
                file << "Case #" << i + 1 << ": " << fixed << setprecision(9) <<-1 << endl;
            }
            else{
                file << "Case #" << i + 1 << ": " << fixed << setprecision(9) <<v_min << endl;
            }
           
        }
        return 0;
    }