class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // BFS will work
        // as it work as level as miniute.

        // first we make make a queue
        // then insert rotten oranges in queue with time = 0;

        int m = grid.size();
        int n = grid[0].size();
        queue<pair<pair<int, int>, int>> q; //{row, column, time}
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 2){ //rotten oranges
                    q.push({{i,j},0});
                }
            }
        }
        int tm = 0;
        vector<int> delrow = {0, 1, 0, -1};
        vector<int> delcol = {1, 0, -1, 0};

        //BFS
        while(q.size() > 0){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;

            // updating tm
            tm = max(tm, t);

            q.pop();

            for(int i=0; i<4; i++){
                int nrow = r + delrow[i];
                int ncol = c + delcol[i];

                if(nrow>=0 && ncol>=0 && nrow<m && ncol<n && grid[nrow][ncol] == 1){
                    grid[nrow][ncol] = 2;
                    q.push({{nrow, ncol}, t + 1});
                }
            }
        }

        //checking
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1) return -1;
            }
        }

        return tm;
    }
};