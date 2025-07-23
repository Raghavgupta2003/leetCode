class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> nge(n);
        int maxi = -1;
        for(int i=n-1; i>=0; i--){
            nge[i] = maxi;
            if(maxi < height[i]) maxi = height[i];
        }

        vector<int> pge(n);
        maxi = -1;
        for(int i=0; i<n; i++){
            pge[i] = maxi;
            if(maxi < height[i]) maxi = height[i];
        }

        int area = 0;
        for(int i=0; i<n; i++){
            int x = min(nge[i], pge[i])-height[i];
            if(x>0) area += x;
        }
        return area;
        
    }
};