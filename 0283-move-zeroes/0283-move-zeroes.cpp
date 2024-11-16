class Solution {
public:
    //Two pointer
    // pointer j remains at zero
    // AND pointer i increases with loop
    // if non zero element found
    // then swap with jth element(because its 0) and increment j;
    void moveZeroes(vector<int>& nums) {
        int j = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                swap(nums[i],nums[j]);
                j++;
            }
        }
    }
};