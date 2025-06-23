class Solution {
public:
    vector<int> delrow = {0, 1, 0, -1};
    vector<int> delcol = {1, 0, -1, 0};
    int orangesRotting(vector<vector<int>>& grid) {

        queue<pair<pair<int,int>, int>> q;

        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == 2){ //rotten
                    q.push({{i,j}, 0}); //0 means 0 minute
                }
            }
        }

        int tmax = 0;
        while(q.size() > 0){
            int r = q.front().first.first;
            int c = q.front().first.second;

            int t = q.front().second;
            tmax = max(tmax, t);

            q.pop();

            for(int i=0; i<4; i++){
                int nr = r + delrow[i];
                int nc = c + delcol[i];

                int nt = t+1;

                if(nr>=0 && nc>=0 && nr<grid.size() && nc<grid[0].size()){
                    if(grid[nr][nc] == 1){//unrotten or unvisited 
                        grid[nr][nc] = 2; //rotten it

                        q.push({{nr, nc}, nt});
                    }
                }
            }
        }

        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == 1){ //if every orange can't be rooten then return -1
                    //still it is fresh
                    return -1;
                }
            }
        }
        return tmax;
        
    }
};