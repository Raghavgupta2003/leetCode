class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        //parity -> number is odd or even.
        bool flag = true;
        for(int i=1;i<nums.size();i++){
            int a = nums[i-1];
            int b = nums[i];
            if(a%2 == 0 && b%2 == 0) return false;
            if(a%2 != 0 && b%2 != 0) return false;

        }
        return true;
    }
};