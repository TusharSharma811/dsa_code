#include <iostream>
#include <vector>
using namespace std;

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int n, k;
        cin >> n >> k;
        bool flag = false;

        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            if (arr[i] == k) {
                flag = true;
          
            }
        }

        if (flag) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
