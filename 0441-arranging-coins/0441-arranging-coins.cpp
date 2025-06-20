class Solution {
public:
    int arrangeCoins(int n) {
        long long low = 1; //since row 1 has 1 coin
        long long high = n;

        while(low<=high){
            long long mid = low + (high-low)/2;
            // cout<<mid<<" ";

            long long sumToMidthRow = (mid * (mid + 1))/2;
            // cout<<sumToMidthRow<<endl;

            if(sumToMidthRow == n) return mid;
            else if(sumToMidthRow < n){
                low = mid+1; 
            }
            else{
                high = mid-1;
            }
        }

        return high;
    }
};