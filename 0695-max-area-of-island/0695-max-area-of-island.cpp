// class DSU{
//     vector<int> parent;
//     int maxSize;

//     public:
//     DSU(int n){
//         parent.resize(n,-1); // n = row * col
//         maxSize = 0;
//     }

//     int find(int x){
//         if(parent[x] < 0) return x;
//         return parent[x] = find(parent[x]);
//     }

//     void unite(int x, int y){
//         int parentX = find(x);
//         int parentY = find(y);

//         if(parentX == parentY){ // both elements have the same parent node, meaning they are already united.
//             return;
//         }
//         // if they are not united.
        
//         if(parent[parentX] <= parent[parentY]){
//             parent[parentX] += parent[parentY];
//             parent[parentY] = parentX;
//             maxSize = max(maxSize, abs(parent[parentX]));
//         } 
//         else {
//             parent[parentY] += parent[parentX];
//             parent[parentX] = parentY;
//             maxSize = max(maxSize, abs(parent[parentY]));
//         }
//     }

//     int getMax(){
//         return maxSize;
//     }
//     void updateMaxSize(int size) {  // <-- New Setter Method!
//         maxSize = max(maxSize, size);
//     }
// };

// class Solution {
// public:
//     int maxAreaOfIsland(vector<vector<int>>& grid) {
//         DSU dl(grid.size() * grid[0].size());
        
//         int rows = grid.size();
//         int cols = grid[0].size();
//         vector<int> dr = {-1, 0, 1, 0, -1};

//         for(int i = 0; i < rows; i++){
//             for(int j = 0; j < cols; j++){
//                 if(grid[i][j] == 1){
//                     dl.updateMaxSize(1);
//                     int cellId = i * cols + j; 
//                     // suppose ids of set are 0,1,2,3,.....m*n
//                     for(int k = 0; k < 4; k++){ // k < dr.size()-1
//                         int ni = i + dr[k]; // row idx of neighbor
//                         int nj = j + dr[k+1]; // col idx of neighbor
//                         int nId = ni * cols + nj; // cellId of neighbor
//                         if(ni >= 0 && nj >= 0 && ni < rows && nj < cols && grid[ni][nj] == 1){
//                             dl.unite(cellId, nId);
//                         }
//                     }
//                 }
//             }
//         }
        
//         return dl.getMax();
//     }
// };

class DSU {
    public:
    vector<int> parent;
    int mxSize;


    DSU(int n) {
        parent.resize(n, -1);
        mxSize = 0;
    }

    int find(int x) {
        if (parent[x] < 0) {
            return x;
        }
        return parent[x] = find(parent[x]); // Path compression
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY) return; // Already connected

        // Union by size
        if (parent[rootX] <= parent[rootY]) {
            parent[rootX] += parent[rootY];  // Update root size
            parent[rootY] = rootX;  // Merge rootY into rootX
            mxSize = max(mxSize, -parent[rootX]);  // Update max size
        } else {
            parent[rootY] += parent[rootX];
            parent[rootX] = rootY;
            mxSize = max(mxSize, -parent[rootY]);
        }
    }

    int getMaxSize() {
        return mxSize;
    }
};

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        DSU dsu(r * c);
        vector<int> d = {-1, 0, 1, 0, -1}; // 4 directions

        // Step 1: Union adjacent "1"s
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 1) {
                    int cellId = i * c + j;
                    for (int k = 0; k < 4; k++) {
                        int ni = i + d[k];
                        int nj = j + d[k + 1];
                        if (ni >= 0 && nj >= 0 && ni < r && nj < c && grid[ni][nj] == 1) {
                            int nId = ni * c + nj;
                            dsu.unite(cellId, nId);
                        }
                    }
                }
            }
        }

        // Step 2: Compute max island area
        int maxArea = 0;
        for (int i = 0; i < r * c; i++) {
            if (grid[i / c][i % c] == 1 && dsu.find(i) == i) {
                maxArea = max(maxArea, -dsu.parent[i]);  // Use absolute value of parent[i]
            }
        }

        return maxArea;
    }
};