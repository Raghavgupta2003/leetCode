class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        int cost = 0;
        int maxLength = 0;
        int i=0;
        int j=0;

        while(i<n){
          cost += abs(s[i] - t[i]);

          while(cost > maxCost){
            cost -= abs(s[j]-t[j]);
            j++;
          }
          maxLength = max(maxLength, i-j+1);
          i++;
        }

        return maxLength;
    }
};