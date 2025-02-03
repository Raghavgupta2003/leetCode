class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        // int n = nums.size();
        // int maxdec=0;
        // int maxinc=0;
        // for(int i=0;i<n-1;i++){
        //     for(int j=0;j<i+1;j++){
        //         if(nums[j]>nums[j+1]){
        //             maxdec++;
        //         }
        //         else if(nums[j+1]>nums[j]){
        //             maxinc++;
        //         }
        //         // else if(nums[j]==nums[j+1]) return 1;
        //     }
        // }
        // if(maxinc>maxdec){
        //     return maxinc;
        // }
        // // else return maxdec;
        // return maxinc;
        
        int n = nums.size();
        int inc = 1;
        int dec = 1;
        int maximum = 1;
        for(int i=1; i<n; i++){
            if(nums[i-1] < nums[i]){
                inc++;
                dec = 1;
            }
            else if(nums[i-1] > nums[i]){
                dec++;
                inc = 1;
            }
            else{
                inc = 1;
                dec = 1;
            }

            maximum = max(maximum, max(dec,inc)); 

        }

        return maximum;
    }
};