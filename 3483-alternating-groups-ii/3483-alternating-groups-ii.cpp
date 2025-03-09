class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int cnt = 0;
        for(int i=0; i<k-1; i++){
            colors.push_back(colors[i]);
        }
        int i=0; 
        int j=1;
        while(j<colors.size()){
            if(colors[j] == colors[j-1]){
                i=j;
                j++;
                continue;
            }
            
            if(j == i+k-1){
                cnt++;
                i++;
            }
            j++;

        }

        return cnt;

    }
};