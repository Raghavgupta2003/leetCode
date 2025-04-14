class Solution {
public:
    //dijkstra
    vector<int> delrow = {1, 0, -1, 0, -1, -1, 1, 1};
    vector<int> delcol = {0, 1, 0, -1, -1, 1, 1, -1};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> distance(m, vector<int> (n, 1e9));

        //here no need of priority queue
        //becase constant increase

        queue<pair<int, pair<int,int>>> q; //{distance, {i, j}};
        if(grid[0][0] == 0){
            q.push({0, {0,0}});
            distance[0][0] = 0;
        }
        else return -1;

        while(q.size() > 0){
            int dist = q.front().first;
            int i = q.front().second.first;
            int j = q.front().second.second;
            
            if(i==m-1 && j==n-1) return dist + 1; //we return number of nodes travelled that is edges + 1
            //reach to (n-1,n-1);
            q.pop();

            for(int k=0; k<8; k++){
                int nrow = i + delrow[k];
                int ncol = j + delcol[k];
                if(nrow >=0 && ncol >=0 && nrow < m && ncol < n){
                    if(grid[nrow][ncol] == 0){ //clear path
                        if(distance[nrow][ncol] > dist + 1){ //minimum distance
                            distance[nrow][ncol] = dist + 1;
                            q.push({dist+1, {nrow, ncol}});
                        }
                    }
                }
            }
        }
        return -1;
    }
};