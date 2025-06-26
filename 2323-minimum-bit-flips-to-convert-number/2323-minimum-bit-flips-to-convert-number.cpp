class Solution {
public:
    int minBitFlips(int start, int goal) {
        //we have to cnt, How many bits are not equal
        //for this, best operator is XOR
        //cnt set bits
        //because bits are only set when different bits in XOR operation

        //**thwew is not concept of minimum in this question**
        int x = start ^ goal;

        //cnting set bit
        int cnt = 0;
        while(x){
            if(x%2 == 1) cnt++;
            x/=2;
        }

        return cnt;

    }
};