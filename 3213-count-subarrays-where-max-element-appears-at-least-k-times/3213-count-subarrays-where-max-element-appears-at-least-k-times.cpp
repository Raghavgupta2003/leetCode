class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        //solve question by reverse thinking
        //find the subarray containing maxEle < k
        //and subtract it from total
        int n = nums.size();
        int maxEle = *max_element(nums.begin(), nums.end());
        
        int cntMax = 0;
        long long cntSubarray = 0; //cnt of subarray containing maxEle < k
        int i=0;
        int j=0;

        while(i<n){
            if(nums[i] == maxEle) cntMax++;

            while(cntMax >= k && j<=i){
                if(nums[j] == maxEle) cntMax--;
                j++;
            }

            cntSubarray += 1LL* (i-j+1); //i-j+1 means subarrays ending at j index 
            i++;
        }

        long long totalSubarrays = (1LL* n * (n + 1) / 2 ); //total subaarys;

        return totalSubarrays - cntSubarray;
        
    }
};