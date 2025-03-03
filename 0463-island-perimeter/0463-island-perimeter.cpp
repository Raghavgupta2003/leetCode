class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        //perimeter of a square is 4.
        //we subtract -2 if we found land.
        int area = 0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == 1){
                    area += 4;
                    if(i-1 >= 0){
                        if(grid[i-1][j] == 1) area -= 2; //self box and previous box boundary.           
                    }
                    if(j-1 >= 0){
                        if(grid[i][j-1] == 1) area -= 2; 
                    }
                }
            }
        }
        return area;
    }
};