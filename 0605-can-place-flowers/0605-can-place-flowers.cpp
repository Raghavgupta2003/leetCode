class Solution {
public:
    bool canPlaceFlowers(vector<int>& arr, int k) {
        
        int cnt = 0;
        int n = arr.size();
        if(k == 0) return true;
        
        if(n == 1 && arr[0] == 0) return true;

        if(n == 2){
            if(k == 1){
                if(arr[0] || arr[1]){
                    return false;
                }
                return true;
            }

            if(k==2){
                return false;
            }
            
        }
        
        if(arr[0]==0 && arr[1]==0){
            cnt++;
            arr[0]=1;
        }
        if(arr[n-1]==0 && arr[n-2]==0){
            cnt++;
            arr[n-1]=1;
        }

        for(int i=1; i<arr.size()-1; i++){
            if(arr[i]==0){
                if(arr[i+1] == 0 && arr[i-1] == 0){
                    cnt++;
                    arr[i] = 1;
                }
            }
        }

        for(int i=0; i<arr.size(); i++){
            cout<<arr[i]<<" ";
        }
        return cnt>=k;
    }
};