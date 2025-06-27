class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorr = 0; //xor of two single digits
        for(int i=0; i<nums.size(); i++){
            xorr = xorr^nums[i];
        }

        //where bits are set in xor of two digits 
        //means there is different digit in the ans.

        //now we find any set bit in xorr (may be rightmost set bit)

        int ithBit = 0;  //setbit
        while(((xorr >> ithBit) & 1) == 0) {   //discarding right side bits
            ithBit++;                          //checking for last bits set or not
        }


        // now divide array in two groups, one whose ith bit is set(1)
        // and other group in ith bit is 0
        //now xoring groups 1
        //and xoring group 2 completely

        int a =0;
        int b =0;

        for(int i=0; i<nums.size(); i++){
            if((nums[i] & (1 << ithBit)) != 0) a ^= nums[i]; //ithBit set
            else b ^= nums[i]; //ithbit not set
        }


        return {a, b};

    }
};