class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        int Max = 0;

        int one = 0;
        for(int i=0;i<n;i++){
            if(s[i]=='1') one++;
        }

        int zero = 0;
        for(int i=0;i<n-1;i++){
            if(s[i]=='0') zero++;
            if(s[i]=='1') one--;

            // Max = max(zero+one ,max)

            int x = zero+one;
            if(Max <= x) Max=x;
        }

        return Max;

    }
};