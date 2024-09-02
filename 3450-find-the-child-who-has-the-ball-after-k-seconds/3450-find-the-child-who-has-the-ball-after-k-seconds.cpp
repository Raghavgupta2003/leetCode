class Solution {
public:
    int numberOfChild(int n, int k) {
        int time = 0;
        int child = 0;
        while(time<k){
            if(child==(n-1)) child*=-1;
            child++;
            time++;
        }
        return abs(child);
    }
};