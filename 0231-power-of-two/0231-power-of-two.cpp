class Solution {
public:
    bool isPowerOfTwo(int n) {
        // power of numbers have there setbit cnt = 1;

        //like: 1 = 001 (2^0);
        //      2 = 010
        //      4 = 100
        //..........

        int cnt = 0;
        while(n){
            if(n%2 == 1) cnt++;
            n/=2;
        }

        return cnt == 1;
    }
};