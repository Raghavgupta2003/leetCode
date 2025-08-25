class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
         int m = mat.size();
         int n = mat[0].size();
         vector<int> v;
         int i=0;
         int j=0;
         
         int dir = 1; //up
         while(v.size() < m*n){
            v.push_back(mat[i][j]);
            if(dir == 1){ //up
                if(j == n-1){ //right boundary hit then row++
                    i+=1;
                    dir = 0;
                }else if(i == 0){ //top boundary hit then column++
                    j+=1;
                    dir = 0;
                }else{
                    //base condition
                    i--;
                    j++;
                }

            }
            else{//down
                if(i == m-1){//bottom boundary hit then column++
                    j+=1;
                    dir = 1;
                }else if(j == 0){//left boundary hit then row++;
                    i+=1;
                    dir = 1;
                }else{
                    i++;
                    j--;
                }

            }
         }
        return v;
    }
};