class Solution {
public:
    int searchInsert(vector<int>& arr, int target) {
        int lo = 0;
        int hi = arr.size()-1;
        while(lo<=hi){
            int mid = (lo + hi)/2;
            if(arr[mid] == target) return mid;
            if(arr[mid] < target) lo = mid  + 1;
            if(arr[mid] > target) hi = mid -1; 
        }
        return hi + 1;
    }
};