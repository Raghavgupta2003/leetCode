// class Solution {
// public:
//     int countSymmetricIntegers(int low, int high) {
//         int cnt = 0;
//         for(int i=low; i<=high; i++){
//             string x = to_string(i);
//             if(x.size()%2 ==0){ //checking only for even size
//                 int j=0;
//                 int k=x.size()-1;
//                 int sum1 = 0;
//                 int sum2 = 0;
//                 while(j<k){
//                     sum1+=x[j];
//                     sum2+=x[k];
//                     j++;
//                     k--;
//                 }
//                 if(sum1 == sum2){
//                     cout<<x<<" ";
//                     cnt++;
//                 } 
//             }           
//         }
//         return cnt;
//     }
// };

//---------------------------------------------------------------

class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int cnt = 0;
        // since odd length cannot be symmetric
        // so, we only check for 11 to 99
        // and 1000 to 10000
        // all digits 100 to 999 are odd so no symmety

        for(int i=low; i<=high; i++){
            if(i >= 11 && i<= 99 && i%11 == 0) cnt++;
            else if(i>=1000 && i<=9999){
                int a = i;
                int x = a%10;
                a/=10;
                int y = a%10;
                a/=10;
                int c = a%10;
                a/=10;
                int b = a%10;

                if(x+y == c+b) cnt++;
            } 
        }
        return cnt;
    }
};