// class Solution {
// public:
//     int cntSet(int n){
//         int cnt = 0;
//         while(n){
//             if((n&1) != 0) cnt++; //0th bit is set

//             n = n>>1; //discard 0th bit
//         }
//         return cnt;
//     }
//     vector<int> countBits(int n) {
//         vector<int> v;
//         for(int i=0; i<n+1; i++){
//             int x = cntSet(i);
//             v.push_back(x);
//         }
//         return v;
//     }
// };



//----------------------------------------

class Solution {
public:
    
    vector<int> countBits(int n) {
        vector<int> arr(n+1, 0);
        for(int i=0; i<n+1; i++){
            if((i%2) == 0) arr[i] = arr[i/2];
            else arr[i] = arr[i/2] + 1;
        }
        return arr;
    }
};