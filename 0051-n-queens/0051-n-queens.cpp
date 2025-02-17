class Solution {
public:
    bool isfilled(vector<string>& v, int n, int row, int col){
        int tempcol = col;
        int temprow = row;

        while(row>=0 && col>=0){         // UPPER left DIAGONAL
            if(v[row][col] == 'Q') return false;
            row--;
            col--;
        }

        col = tempcol;
        row = temprow;
        while(col>=0){  // left
            if(v[row][col] == 'Q') return false;
            col--;
        }


        col = tempcol;
        row = temprow;
        while(row<n && col>=0){         // lower left DIAGONAL
            if(v[row][col] == 'Q') return false;
            row++;
            col--;
        }

        return true;
    }
    void  Nqueen(vector<vector<string>> &ans, vector<string> &v, int n, int col){
        if(col >= n){
            ans.push_back(v);
            return;
        }
        for(int row=0; row<n; row++){
            if(isfilled(v,n,row,col)){
                v[row][col] = 'Q';
                Nqueen(ans, v, n, col+1);
                v[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        string s(n, '.');
        vector<string> v(n,s);
        Nqueen(ans, v, n, 0);
        // for(int i=0; i<v.size(); i++){
        //     for(int j=0; j<v[0].size();j++){
        //         cout<<v[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return ans;
    }
};