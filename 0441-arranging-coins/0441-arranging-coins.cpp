class Solution {
public:
    int arrangeCoins(int n) {
        //-------------Brute Force-------------
        if(n==1) return 1;

        int size = n; //since n is decreasing in loop, so prefer to use another variable for proper iteration in a array.
        for(int i=1; i<=size; i++){
            if(n - i >= 0) n = n-i;
            else{
                return i-1;
            }

        }
        return -1;
    }
};