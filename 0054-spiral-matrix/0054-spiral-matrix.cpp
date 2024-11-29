class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& arr) {
        int m = arr.size();
        int n = arr[0].size();
        int left = 0;
        int top = 0;
        int bottom = m-1;
        int right = n-1;
        vector<int> v;
        while(left<=right && top<=bottom){

            for(int i=left;i<=right;i++){
                v.push_back(arr[top][i]);
            }
            top++;

            for(int i=top;i<=bottom;i++){
                v.push_back(arr[i][right]);
            }
            right--;


        if(left<=right && top<=bottom){
            for(int i=right;i>=left;i--){
                v.push_back(arr[bottom][i]);
            }
            bottom--;
        }

        if(left<=right && top<=bottom){
            for(int i=bottom;i>=top;i--){
                v.push_back(arr[i][left]);
            }
            left++;
        }

        }

        return v;

    }
};