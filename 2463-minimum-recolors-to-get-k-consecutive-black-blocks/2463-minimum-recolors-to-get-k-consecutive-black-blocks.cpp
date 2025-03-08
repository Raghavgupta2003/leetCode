class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int windowsize = k;
        int countWhite = 0;
        int mini = INT_MAX; 
        
        int i=0; 
        int j=0;
        while(j<blocks.size()){
            if(blocks[j] == 'W'){
                countWhite++;
            }
            if(j == i + windowsize - 1){
                mini = min(mini, countWhite);
                if(blocks[i] == 'W'){
                    countWhite--;
                }
                i++;
            }
            j++;
        }
        return mini;
    }
};