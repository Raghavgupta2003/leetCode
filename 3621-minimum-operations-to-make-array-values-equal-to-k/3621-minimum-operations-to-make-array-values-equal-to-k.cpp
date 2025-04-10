class Solution {
public:
    
    int minOperations(vector<int>& nums, int k) {
        //basecase
        //when any element is less than k, we return -1
        //because we are not able to convert all elements equal to k.
        for(int i=0; i<nums.size(); i++){
            if(nums[i]<k) return -1;
        }

        //sort to find valid h
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int cnt = 0;

        // selecting valid h and replace all greater than it by h.
        for(int i=nums.size()-1; i>0; i--){
            if(nums[i]!=nums[i-1]){
                int h = nums[i-1];
                for(int j=i; j<nums.size(); j++){
                    nums[j] = h;
                }
                cnt++;
            }
        }

        if(nums[0] > k) cnt = cnt+1; // this is a case when our all elements become equal but less greater than k. In this case, our h = k.
        
        if(k > nums[0]) return -1; //this is case when we are not able to make our array equal to k.
        return cnt;
        
    }
};