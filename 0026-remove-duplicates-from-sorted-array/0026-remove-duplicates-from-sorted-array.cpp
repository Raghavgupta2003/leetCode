class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = 1;
        while(i<n && j<n){
            while(j<n &&  (nums[j-1] == nums[j])){
                j++;
            }
            //now j is on new number.
            
            if(j>=n) break;
            i++;
            nums[i] = nums[j];
            j++; 
        }
        return i+1; //since i start from zero. so size of sorted one is i+1.
    }
};