class Solution {
public:
    int hammingWeight(int n) {
        // int cnt = 0;
        // while(n){
        //     if(n%2 == 1){ //set bit
        //         cnt++;
        //     }
        //     n/=2;
        // }
        // return cnt;


        //------------------------------------------

        // int countsets = 0;
        // for(int i=0; i<32; i++){
        //     if((n & (1<<i)) != 0) countsets++;
        // }
        // return countsets;

        //--------------------
         int cnt = 0;
        while(n){
            if((n&1) != 0) cnt++; //0th bit is set

            n = n>>1; //discard 0th bit
        }
        return cnt;
    }
};