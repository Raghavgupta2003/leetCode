class Solution {
public:
    int ansMIN = INT_MAX;
    void solve(int idx, vector<int>& children, vector<int>& cookies, int k){
        //basecase
        if(idx == cookies.size()){
            int maxi = INT_MIN;
            for(int i=0; i<children.size(); i++){
                maxi = max(maxi, children[i]);
            }

            ansMIN = min(ansMIN, maxi);
            return;
        }

        for(int i=0; i<k; i++){ //child traversal
            int cookie = cookies[idx];

            children[i]+=cookie;
            solve(idx+1, children, cookies, k);
            children[i]-=cookie;

        }
    }
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> children(k, 0);

        solve(0, children, cookies, k);

        return ansMIN;
    }
};