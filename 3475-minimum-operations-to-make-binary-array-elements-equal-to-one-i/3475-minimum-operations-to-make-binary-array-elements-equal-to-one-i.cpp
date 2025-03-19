class Solution {
public:
    //flipping all bits means XOR 1
    // 0^1 = 1;
    // 1^1 = 0;
    // 0^0 = 1;
    // samebits = 0, different bits = 1;
    int minOperations(vector<int>& nums) {
        int cnt = 0;
        for(int i=0; i<nums.size()-3+1; i++){
            if(nums[i] == 0){
                nums[i] ^= 1;
                nums[i+1] ^= 1;
                nums[i+2] ^= 1;
                cnt++;
            }
        }
        
        //checking all bits are set to 1 or not;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 0) return -1;
        }

        return cnt;
    }
};