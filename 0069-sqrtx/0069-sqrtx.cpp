class Solution {
public:
    int mySqrt(int x) {
        int low = 0;
        int high = x;
        int ans = -1;
        while(low<=high){
            long long mid = low + ((high-low)/2);
            
            if(mid*mid == x){
                return mid;
            }
            else if(mid*mid < x){
                // if((mid+1)*(mid+1) > x)  return mid;
                low = mid+1;
            }
            else if(mid*mid > x){
                high = mid-1;
            }
        }

        return high;   //lower bound concept;
    }
};