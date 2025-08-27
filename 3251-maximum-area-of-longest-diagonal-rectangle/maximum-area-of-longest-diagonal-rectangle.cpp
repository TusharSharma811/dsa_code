class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
          int length, width;
        double DiagonalLength;
        double past = 0, now = 0;
        int NowAria = 0, PastAria = 0; 

        for (int i = 0; i < dimensions.size(); i++) {
            length = dimensions[i][0];
            width = dimensions[i][1];

            DiagonalLength = sqrt((length * length) + (width * width));
            int area = length * width;
            
            now = DiagonalLength;
            NowAria = area;
            
            if (now > past) {
                past = now;
                PastAria = NowAria;
            } else if (now == past && NowAria > PastAria) {
                PastAria = NowAria;
            }
        }

        return PastAria;
    }
};