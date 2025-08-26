class Solution {
public:
    double diagonal(int a, int b){
        a *= a;
        b *= b;
        double dia = sqrt(a*1.0  + b*1.0 );
        return dia;
    }
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        double maxDia = 0;
        int maxArea = 0;
        for(int i=0; i<dimensions.size(); i++){
            double dia = diagonal(dimensions[i][0], dimensions[i][1]);
            if(maxDia < dia){
                maxDia = dia;
                maxArea = dimensions[i][0] * dimensions[i][1];
            }else if (abs(dia - maxDia) < 1e-9) { // diagonals equal
            //when both diagonals almost equal or have very minimum diff
            // then we also check
            // becase minor snmall can have maxarea
            //1×10 ^ −9 = 0.000000001
                maxArea = max(maxArea, dimensions[i][0] * dimensions[i][1]);
            }
        }
        return  maxArea;
    }
};