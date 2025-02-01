class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans(k);
        if(arr.size()==1) return arr;
        //case 1
        if(x < arr[0]){
            for(int i=0; i<k; i++){
                ans[i] = arr[i];
            }
            return ans;
        }
        //case 2
        if(x > arr[arr.size()-1]){
            int n = k-1;
            int i=arr.size()-1;
            while(n>=0){
                ans[n] = arr[i];
                n--;
                i--;
            }
            return ans;
        }
        //case 3
        bool flag = false;
        int low = 0;
        int high = arr.size()-1;
        int idx=0;
        int mid;
        while(low<=high){
            mid = low + ((high-low)/2);

            if(arr[mid]==x){
                flag = true;
                ans[idx] = arr[mid];
                idx++;
                break;
            }
            else if(arr[mid] < x){
                low = mid+1;
            }
            else if(arr[mid] > x){
                high = mid -1;
            }
        }
        int lb = high;
        int ub = low;
        if(flag == true){
            lb = mid - 1;
            ub = mid + 1;
        }

        while(lb>=0 && ub<arr.size() && idx<k){
            int a = abs(arr[lb] - x);
            int b = abs(arr[ub] - x);
            if(a<=b){
                ans[idx] = arr[lb];
                idx++;
                lb--;
            }
            else{
                ans[idx] = arr[ub];
                idx++;
                ub++;
            }
        }
        if(lb<0){
            while(idx<k){
                ans[idx] = arr[ub];
                ub++;
                idx++;
            }
        }
        if(ub==arr.size()){
            while(idx<k){
                ans[idx] = arr[lb];
                lb--;
                idx++;
            }
        }

        sort(ans.begin(),ans.end());
        return ans;
    }
};