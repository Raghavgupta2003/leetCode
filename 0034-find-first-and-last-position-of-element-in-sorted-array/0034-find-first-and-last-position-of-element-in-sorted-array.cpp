class Solution {
public:
    int binarySearchfirst(vector<int> &arr, int target){
        int low = 0;
        int high = arr.size()-1;

        while(low<=high){
            int mid = low + ((high-low)/2);

            if(arr[mid]==target){
                if(mid!=0 && arr[mid-1] == target){
                    high = mid-1;
                }
                else{
                    return mid;
                }
            }
            else if(arr[mid] < target) low = mid+1;
            else if(arr[mid] > target) high = mid-1;
        }

        return -1;
    }

     int binarySearchlast(vector<int> &arr, int target){
        int low = 0;
        int high = arr.size()-1;
        

        while(low<=high){
            int mid = low + ((high-low)/2);

            if(arr[mid]==target){
                if(mid!=arr.size()-1 && arr[mid+1] == target){
                    low = mid+1;
                }
                else{
                    return mid;
                }
            }
            else if(arr[mid] < target) low = mid+1;
            else if(arr[mid] > target) high = mid-1;
        }

        return -1;
    }

    
    vector<int> searchRange(vector<int>& nums, int target) {

        int firstocc = binarySearchfirst(nums, target); 
        int lastocc = binarySearchlast(nums, target);
        vector<int> ans = {firstocc, lastocc};

        return ans;

    }
};