class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        long long nn = n;
        if(nn < 0) nn*=-1;
        while(nn>0){
            if(nn%2==0){
                x=x*x;
                nn=nn/2;
            }
            else{
                ans*=x;
                nn = nn-1;
            }
        }

        if(n<0) return 1/ans;

        return ans;
        
    }
};