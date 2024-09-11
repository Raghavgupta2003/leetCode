class Solution {
public:
   int binary(int num){
        int bin = 0;
        int cnt=0;
        int count1=0;
        while(num>0){
            int temp = num%2;
            if(temp==1) count1++;
            // bin+= temp*(pow(10,cnt));
            num/=2;
            cnt++;
        }
        return count1++;
   }
    int minBitFlips(int start, int goal) {
        int ans = start ^ goal;
        return binary(ans);
    }

};