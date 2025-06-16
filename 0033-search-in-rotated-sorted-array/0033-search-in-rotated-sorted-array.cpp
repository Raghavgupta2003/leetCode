class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;

        while(low <= high){
            int mid = low + (high - low)/2;
            
            
            if(nums[mid] == target) return mid;
            else if(nums[low] <= nums[mid]){//left sorted
                if(nums[low]<=target && target<=nums[mid]){
                    //we will reduce space
                    high = mid-1;
                }
                else{
                    low = mid + 1;
                }
            }else{ //right sorted
                if(nums[mid]<=target && target<=nums[high]){
                    //reduce space
                    low = mid+1;
                }
                else{
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};