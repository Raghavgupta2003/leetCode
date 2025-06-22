class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    //---------------BRUTE FORCE---------------
        // int cnt = 0;
        // for(int i=0; i<nums.size(); i++){
        //     int pdt = 1;
        //     for(int j=i; j<nums.size(); j++){
        //         pdt *= nums[j];
        //         if(pdt >= k) break;

        //         if(pdt < k){
        //             cnt++;
        //         } 
        //     }
        // }

        // return cnt;
    
    //----------OPTIMIZED--------------------
        int n = nums.size();
        int j = 0;
        int pdt = 1;
        int cnt = 0;
        for(int i=0; i<n; i++){
            pdt *= nums[i];

            while(pdt >= k && j<=i){
                pdt /= nums[j]; //reducing window size
                j++;
            }

            cnt += i-j+1; //number of subarrays ending at index j
        }

        return cnt;
    }
};