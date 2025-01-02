
    #include <iostream>
    #include <cmath>
    #include <iomanip>

    double required_increase(int N, int P) {
        double original_success_rate = pow(P / 100.0, N);
        double new_success_rate = pow(P / 100.0, N - 1);
        double required_new_P = pow(new_success_rate, 1.0 / N) * 100;
        return required_new_P - P;
    }

    int main() {
        int T;
        std::cin >> T;
        for (int i = 0; i < T; ++i) {
            int N, P;
            std::cin >> N >> P;
            double increase = required_increase(N, P);
            std::cout << "Case #" << i + 1 << ": " << std::fixed << std::setprecision(6) << increase << std::endl;
        }
        return 0;
    }