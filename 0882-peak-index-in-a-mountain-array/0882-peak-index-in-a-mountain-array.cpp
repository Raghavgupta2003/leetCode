class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        // int n = arr.size()-1;
        // for(int i = 1; i<=n-1; i++){
        //     if((arr[i] > arr[i-1]) && (arr[i] > arr[i+1])){
        //         return i;
        //     }
        // }
        // return 0;


        //**********Binary Search*******

        // int low = 1;
        // int high = arr.size()-2;

        // while(low<=high){
        //     int mid = low + ((high - low)/2);

        //     if((arr[mid]>arr[mid-1]) && (arr[mid]>arr[mid+1])){
        //         return mid;
        //     } 
        //     else if( (arr[mid]>arr[mid-1]) && (arr[mid] < arr[mid+1]) ){
        //         low = mid+1;
        //     }
        //     else if((arr[mid] < arr[mid-1]) && (arr[mid]>arr[mid+1])){
        //         high = mid-1;
        //     }
        // }
        // return 0;

        //**********Binary Search***********

        int low = 1;
        int high = arr.size()-2;

        while(low<=high){
            long long mid = low + ((high - low)/2);

            if((arr[mid]>arr[mid-1]) && (arr[mid]>arr[mid+1])){
                return mid;
            } 
            else if(arr[mid] < arr[mid+1]){
                low = mid+1;
            }
            else if(arr[mid] < arr[mid-1]){
                high = mid-1;
            }
        }
        return 0;
    }
};