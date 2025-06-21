class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int cnt = 0;
        for(int i=0; i<nums.size(); i++){
            int pdt = 1;
            for(int j=i; j<nums.size(); j++){
                pdt *= nums[j];
                if(pdt >= k) break;

                if(pdt < k){
                    cnt++;
                } 
            }
        }

        return cnt;
    }
};