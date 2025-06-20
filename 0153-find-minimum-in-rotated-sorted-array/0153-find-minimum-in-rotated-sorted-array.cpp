class Solution {
public:
    int findMin(vector<int>& nums) {
        //-------Brute force-------
        // int minimum = INT_MAX;
        // for(int i=0; i<nums.size(); i++){
        //     if(minimum > nums[i]) minimum = nums[i];
        // }
        // return minimum;

        //---------Optimal--------

        // After rotating the Array, 
        // we can divide array in 2 parts
        // 1) sorted half
        // 2) unsorted half
        // our minimum either exist in sorted half or unsorted half

        // first we have to check which part is sorted by condition
        // arr[low] <= arr[mid] for left half same by right half;
        // store minimumAns = nums[low];
        // if not present in sorted half, we check in unsorted half
        // ckeck again in sorted half
        // and ckeck if arr[low] < mid or not...?

        int low = 0;
        int high = nums.size()-1;
        
        int ans = INT_MAX;
        while(low<=high){
            int mid = low + ((high - low)/2);


            if(nums[low] <= nums[mid]){
                //left part sorted half
                if(nums[low] <= ans){
                    ans = nums[low];
                }
                low = mid+1; //we exit from sorted half
            }


            if(nums[mid] <= nums[high]){
                //right part is sorted half
                if(nums[mid] < ans){
                    ans = nums[mid];
                }
                high = mid-1; //we exit from right sorted
            }
        }

        return ans;

    }
};