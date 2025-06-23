class Solution {
public:
    vector<int> delrow = {1, 0, -1, 0};
    vector<int> delcol = {0, 1, 0, -1};
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        queue<pair<int, int>> q;

        q.push({sr, sc});

        int startColor = image[sr][sc];
        
        image[sr][sc] = color; //colored the source

        while(q.size() > 0){
            int r = q.front().first;
            int c = q.front().second;

            q.pop();

            for(int k=0; k<4; k++){
                int nr = r + delrow[k];
                int nc = c + delcol[k];

                if(nr >= 0 && nc >= 0 && nr < image.size() && nc < image[0].size()){
                    if(image[nr][nc] != color){ //not visited
                        if(image[nr][nc] == startColor){
                            image[nr][nc] = color;
                            q.push({nr, nc});
                        }
                    }
                }
            }
        }

        return image;
        
    }
};