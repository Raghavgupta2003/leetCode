class Solution {
public:
    int sumBase(int n, int k) {
        // string str = "";
        int sum = 0;
        while(n){
            // str = to_string(n%k) + str; //remainderss
            sum += (n%k);
            n/=k;
        }

        return sum;
    }
};