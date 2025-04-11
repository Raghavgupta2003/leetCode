class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        // to find distance of nearest zero
        // we start from 0 and apply BFS we come to know all the four direction of 0 has nearest distance 1 from 0.

        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> visited(m, vector<int>(n, 0));
        vector<vector<int>> distance(m, vector<int>(n, 0));

        queue<pair<pair<int,int>, int>> q; //{row, column, distance}

        //pushing all zeroes to queue with distance 0
        // mark visited as 1
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j] == 0){
                    q.push({{i, j}, 0});
                    visited[i][j] = 1;
                }
            }
        }

        //vector to iterate all 4 direction
        vector<int> delrow = {0, 1, 0, -1};
        vector<int> delcol = {1, 0, -1, 0};

        //appling BFS

        while(q.size() > 0){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int dist = q.front().second;
         
            distance[r][c] = dist;

            q.pop();

            //iterating in four direction and checking if already visited
            for(int i=0; i<4; i++){
                int nrow = r + delrow[i];
                int ncol = c + delcol[i];

                if(nrow>=0 && ncol>=0 && nrow<m && ncol<n){
                    if(!visited[nrow][ncol]){
                        q.push({{nrow, ncol}, dist + 1});
                        visited[nrow][ncol] = 1;
                    }
                }
            }
        }

        return distance;
    }
};