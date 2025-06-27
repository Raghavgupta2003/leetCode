class Solution {
public:
    vector<int> delrow = {1, 0, -1, 0};
    vector<int> delcol = {0, 1, 0, -1};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        //in this question we have to find the distance of nearest 0 , so, we try to start from 0.

        vector<vector<int>> visited(m, vector<int>(n, 0));
        vector<vector<int>> distance(m, vector<int>(n, 0));

        queue<pair<pair<int, int>, int>> q; //{{i, j}, dist};

        //pushing where 0 found as 0 distance to nearest 0 is 0
        //mark them visited

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j] == 0){
                    q.push({{i, j}, 0});
                    visited[i][j] = 1;
                }
            }
        }

        //BFS TRAVERSAL IN WHICH WE INCREASE DIST BY ONE

        while(q.size() > 0){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int dist = q.front().second;

            q.pop();

            for(int i=0; i<4; i++){
                int nr = r + delrow[i];
                int nc = c + delcol[i];

                if(nr >= 0 && nc >=0 && nr < m && nc <n){
                    if(!visited[nr][nc]){
                        q.push({{nr, nc}, dist + 1});
                        visited[nr][nc] = 1;
                        distance[nr][nc] = dist+1;
                    }
                }
            }
        }

        return distance;
    }
};