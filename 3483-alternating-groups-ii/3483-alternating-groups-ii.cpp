class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        int ans =0;
        int len = 1;
        for(int i=1; i<n + (k-1); i++){
            // loop till n + (k-1)
            // becase we have to check window of k size
            // last index + (k-1)indexes from start
            if(colors[i%n]!=colors[(i-1+n)%n]){
                len++;
            }else{
                len = 1;
            }

            if(len >= k){
                ans++;
            }
        }
        return ans;
    }
};