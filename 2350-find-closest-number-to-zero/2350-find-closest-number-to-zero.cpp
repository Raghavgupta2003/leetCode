class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int arr[1000];
        int length = nums.size();
        for(int i=0;i<length;i++)
        {
            arr[i]=nums[i];
            if(arr[i]<0)
            {
                arr[i]=-arr[i];
            }
            
        }
        int smallest = arr[0];
        int index = 0;
        for(int i=0;i<length;i++)
        {
            if(smallest>arr[i])
            {
                smallest = arr[i];
                index = i;
            }
        }
        int count =0;
        for(int i=0;i<length;i++)
        {
            if(smallest==arr[i])
            {
                count++;
            }
        }
        // if(count>1)
        // {
        //     return smallest;
        // }
        // else if(nums[index]==arr[index])
        // {
        //     return smallest;
        // }
        // else
        // {
        //     return -smallest;
        // }

        int ans = 0;
        for(int i=0; i<nums.size(); i++){
            if(smallest == abs(nums[i])){
                ans = nums[i];
            }
        }

        return ans;
        
        
    }
};