
    #include <iostream>
    #include <cmath>
    #include <iomanip>
    #include<fstream>
    using namespace std ;

    int main() {
        int T;
        cin >> T;
         ofstream file("output1.txt");
        for (int i = 0; i < T; ++i) {
            double n, p;
            cin >> n >> p;
            double pnew = 100 * (pow(p/100.0 , (n-1)/n)) ;

            double increase = pnew - p ;
            file << "Case #" << i + 1 << ": " <<fixed<< setprecision(15) << increase << endl;
        }
        return 0;
    }