class Solution {
public:
    int compress(vector<char>& chars) {
        int size = 0;
        char current = chars[0];
        int count = 1;
        for(int i = 1; i < chars.size(); ++i) {
            if(current != chars[i]) {
                chars[size] = current;
                size++;
                if(count > 1) {
                    auto s = to_string(count);
                    int j = 0;
                    while(j < s.size()) {
                        chars[size] = s[j];
                        size++;
                        j++;
                    }
                }
                current = chars[i];
                count = 0;
            }
            count++;
        }
        chars[size] = current;
        size++;
        if(count > 1) {
            auto s = to_string(count);
            int j = 0;
            while(j < s.size()) {
                chars[size] = s[j];
                size++;
                j++;
            }
        }
        return size;        
    }
};