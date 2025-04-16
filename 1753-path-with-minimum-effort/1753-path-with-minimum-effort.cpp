class Solution {
public:
    //dijkstra algorithm
    vector<int> delrow = {1, 0, -1, 0};
    vector<int> delcol = {0, 1, 0, -1};
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> distance(m, vector<int>(n, 1e9));
        //here we store absolute difference of two cells and update it

        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;
        pq.push({0, {0, 0}});
        distance[0][0] = 0;
        
        while(pq.size() > 0){
            int diff = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;
   
            if(i==m-1 && j==n-1){
               //minimum effort calculating
                return diff;
            }

            pq.pop();

            for(int k=0; k<4; k++){
                int nrow = i + delrow[k];
                int ncol = j + delcol[k];
                 
                if(nrow >= 0 && ncol >=0 && nrow<m && ncol<n){
                     int Newdiff = max(diff, abs(heights[i][j] - heights[nrow][ncol])); 
                     //in a path we store maximum efforts
                     //example [[1,10,6,7,9,10,4,9]]
                     //effort of this path is continuosly changing
                     // so, when we reach destination we have max effort of that path.
                     //we have to store 10-1 = 9 always
        

                     if(distance[nrow][ncol] > Newdiff){
                        distance[nrow][ncol] = Newdiff; //updating distance array
                        pq.push({Newdiff, {nrow, ncol}});
                     }
                }
            }
        }

        return 0; //unreachable
    }
};