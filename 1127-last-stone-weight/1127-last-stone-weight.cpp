// class Solution {
// public:
//     int lastStoneWeight(vector<int>& stones) {
//         while(stones.size() > 1){
//             sort(stones.begin(), stones.end());
//             int n = stones.size();

//             int x = stones[n-2];
//             int y = stones[n-1];

//             if(x==y){ //destroy
//                 stones.pop_back();
//                 stones.pop_back();
//             }else{
//                 //x<y
//                 stones.pop_back();
//                 stones.back() = y-x;
//             }
//         }

//         if(stones.size() < 1) return 0;
//         return stones[0];
//     }
// };


//------------optimizing it by max heap as max elements are top--------------


class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxheap;

        for(int i=0; i<stones.size(); i++){
            maxheap.push(stones[i]);
        }
        ///here we need not to sort again and again heap auto sort
        while(maxheap.size() > 1){
            int y = maxheap.top();
            maxheap.pop();

            int x = maxheap.top();
            maxheap.pop();

            if(x==y) continue;
            else{
                //x < y

                maxheap.push(y-x);
            }
        }
        if(maxheap.size() < 1) return 0;
        return maxheap.top();
    }
};