class Solution {
public:
    int search(vector<int>& arr, int target) {
        int low = 0;
        int high = arr.size()-1;

        while(low<=high){
            long long mid = low + ((high-low)/2);

            if(arr[mid] == target) return mid;
            else if(arr[low] <= arr[mid]){//left half is sorted
                //checking if target lies in left sorted part

                if(arr[low]<=target && arr[mid]>=target){
                    high = mid-1;
                }
                else{
                    low = mid+1;
                }

            }
            else{//right half is sorted
                //checking if target lies in right sorted part

                if(target>=arr[mid]  && target<=arr[high]){
                    low = mid+1;
                }
                else{
                    high = mid-1;
                }
            }
        }

        return -1;
    }
};