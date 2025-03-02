class Solution {
public:
    void move(int row, int col, vector<vector<char>>& ans){
          for(int i=row; i<ans.size(); i++){
            if(ans[i][col] == '.'){
                swap(ans[row][col], ans[i][col]);
                break;
            }
            if(ans[i][col] == '*'){
                break;
            }
            
          }
    } 
    vector<vector<char>> rotate(vector<vector<char>>& boxGrid) {
        int m = boxGrid.size();
        int n = boxGrid[0].size();

        //rotate
        vector<vector<char>> ans(n, vector<char>(m));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                ans[j][i] = boxGrid[i][j];
            }
        }
        for(int i=0; i<ans.size(); i++){
            reverse(ans[i].begin(), ans[i].end());
        }
        //Gravity
       for(int i=0; i<ans.size(); i++){
            for(int j=0; j<ans[0].size(); j++){
                if(ans[i][j] == '#'){
                    move(i, j, ans);
                }
            }
        } 

        return ans;
    }
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        vector<vector<char>> ans = rotate(boxGrid);
        // for(int i=0; i<ans.size(); i++){
        //     for(int j=0; j<ans[0].size(); j++){
        //         cout<<ans[i][j];
        //     }
        // } 

        return ans;
    }
};