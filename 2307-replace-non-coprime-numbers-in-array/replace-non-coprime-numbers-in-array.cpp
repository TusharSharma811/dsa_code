class Solution {
public:
    long long gcd(long long a, long long b) {
        while (b != 0) {
            long long temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    vector<int> replaceNonCoprimes(vector<int>& nums) {
        stack<long long> st;

        for (auto num : nums) {
            st.push(num);
            while (st.size() >= 2) {
                long long b = st.top(); st.pop();
                long long a = st.top(); st.pop();
                long long g = gcd(a, b);

                if (g == 1) {
                    st.push(a);
                    st.push(b);
                    break;
                } else {
                    long long lcm = a * b / g;
                    st.push(lcm);
                }
            }
        }
        vector<int> ans(st.size());
        for (int i = st.size() - 1; i >= 0; --i) {
            ans[i] = st.top();
            st.pop();
        }

        return ans;
    }
};
