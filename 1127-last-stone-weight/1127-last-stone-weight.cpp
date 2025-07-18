class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        while(stones.size() > 1){
            sort(stones.begin(), stones.end());
            int n = stones.size();

            int x = stones[n-2];
            int y = stones[n-1];

            if(x==y){ //destroy
                stones.pop_back();
                stones.pop_back();
            }else{
                //x<y
                stones.pop_back();
                stones.back() = y-x;
            }
        }

        if(stones.size() < 1) return 0;
        return stones[0];
    }
};