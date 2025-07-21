class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> arr = nums;
        sort(nums.begin(), nums.end());
        int i=0;
        int j=nums.size()-1;

        int a = -1;
        int b = -1;
        while(i<=j){
            if(nums[i] + nums[j] == target){
                a = nums[i];
                b = nums[j];
                i++;
                j--;
                break;
            }
            else if(nums[i] + nums[j] < target){
                i++;
            }
            else{
                j--;
            }
        }
        cout<<a<<" "<<b;
        int k =-1;
        int l = -1;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == a && k == -1) k = i; // ✅ pick first occurrence of a
            else if (arr[i] == b && l == -1) l = i; // ✅ pick first occurrence of b
        }

        return {k, l};
    }
};