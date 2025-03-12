class Solution {
public:
    int maximumCount(vector<int>& nums) {
        // int low = 0;
        // int high = nums.size()-1;
        // while(low<=high){
        //     int mid = low + (high-low)/2;

        //     if(nums[mid] == 0){
                
        //     }
        //     else if(nums[mid]<0){
        //         high = mid-1;
        //     }
        //     else if(nums[mid]>0){
        //         low = mid + 1;
        //     }
        //}
        int pos = 0;
        int neg = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]>0) pos++;
            if(nums[i]<0) neg++;
        }
        return max(pos,neg);
    }
};