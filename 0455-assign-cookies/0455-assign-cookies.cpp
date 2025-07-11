class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int i=g.size()-1;
        int j=s.size()-1;
        
        int child = 0;
        while(i>=0 && j>=0){
            if(s[j] >= g[i]){
                //assign cookie
                j--;
                i--;
                child++;
            }
            else{
                i--; //escaping child and move to next child
            }

        }
        return child;
    }
};