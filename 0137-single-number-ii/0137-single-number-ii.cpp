class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for(int i=0; i<32; i++){
            int cntzero  = 0;
            int cntone = 0;
            for(int j=0; j<nums.size(); j++){
                if((nums[j] & (1<<i)) != 0) cntone++;
                else cntzero++;
            }

            //no need to change result if zero is extra
            //only check cnt of ones

            if(cntone % 3 != 0){
                result = (result | (1<<i));
            }
        }
        return result;
    }
};