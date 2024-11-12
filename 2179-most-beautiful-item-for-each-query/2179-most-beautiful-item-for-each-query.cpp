// APPROACH 1 ----> TIME LIMIT EXCEEDED

// class Solution {
// public:
//     vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
//         sort(items.begin(),items.end());
//         vector<int> v;
//         for(int i=0;i<queries.size();i++){
//             int x = queries[i];
//             int max = 0;
//             for(int j=0;j<items.size();j++){
//                 if(items[j][0]<=x){
//                     int ans = items[j][1];
//                     if(max<=ans) max = ans;
//                 }
//                 else break;
//             }
//             v.push_back(max);
//         }
//         return v;
//     }
// };


// APPROACH 2 -------> COPY PASTE

#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int maxI = INT_MAX;
        vector<vector<int>> res = {{0, 0, maxI}};

        sort(items.begin(), items.end());

        for (const auto& item : items) {
            int price = item[0];
            int beauty = item[1];
            if (beauty > res.back()[1]) {
                res.back()[2] = price;
                res.push_back({price, beauty, maxI});
            }
        }

        vector<int> ans;

        for (int x : queries) {
            for (int i = res.size() - 1; i >= 0; i--) {
                if (res[i][0] <= x) {
                    ans.push_back(res[i][1]);
                    break;
                }
            }
        }

        return ans;
    }
};
