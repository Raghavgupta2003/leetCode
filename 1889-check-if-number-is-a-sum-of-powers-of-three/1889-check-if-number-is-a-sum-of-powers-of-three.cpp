class Solution {
public:
    bool checkPowersOfThree(int n) {
        // we convert n into ternary number.
        //ternary number is a number which has digits 0,1,2 at  base 3.
        //like binary number is a number which has digits 0,1 at  base 2.
        // ternary of 12 = 0
        while(n>0){
            int rem = n%3;
            if(rem == 2) return false;
            n/=3;
        }
        return true;
    }
};