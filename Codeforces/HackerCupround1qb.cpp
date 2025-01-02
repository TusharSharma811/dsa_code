
    #include <iostream>
    #include<bits/stdc++.h>
    #include <cmath>
    #include <iomanip>
    #include<limits>
    #include<fstream>
    using namespace std ;



void sieve(int N , vector<bool>& is_prime ) {
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i * i <= N; ++i) {
        if (is_prime[i]) {
            for (int j = i*i ; j<=N ; j+=i) {
                is_prime[j] = false;
            }
        }
    }

    return ;
}
int count_subtractorizations(int N, const vector<bool>& primes) {
    int count = 0;

    for (int p = 2; p <= N; p++) {
        if (primes[p]) {
            for (int a = 2; a <= N; a++) {
                if (primes[a] && p + a <= N && primes[p + a]) {
                    
                    count++;
                    break;
                }
            }
        }
    }

    return count;
}
    int main() {
        int T;
         ifstream inpfile("inputfile.txt") ;
        inpfile >> T;
         ofstream file("output4.txt");
        
        for (int i = 0; i < T; ++i) {
            int n ;
            inpfile>>n ;
            vector<bool> is_prime(n , 1) ;
            sieve(n , is_prime ) ;
            int ans = count_subtractorizations(n , is_prime) ;
            file << "Case #" << i + 1 << ": " << ans << endl;
            
        }
        return 0;
    }