class Solution {
public:
    bool DFS(int node, int rang, vector<int>& color, vector<vector<int>>& graph){
        color[node] = rang; //giving color to source node

        for(auto it : graph[node]){
            if(color[it] == -1){
                if(!DFS(it, !rang, color, graph)) return false;
            }
            else{
                //already colored
                if(color[it] == color[node]){
                    return false;
                }
            }
        }

        return true;

    }
    bool isBipartite(vector<vector<int>>& graph) {
        // its something like we want to color the graph with 2 colors, but no two adjancent nodes should have same color
        // we assume 2 colors be 0, 1
        // unclored be -1
        //if we get alreadycolred adjacent with samecolr return false;
        //else return true

        //*************this question easily solved by BFS as well as DFS****

        //connected components
        
        int n = graph.size();
        vector<int> color(n, -1); //visited arr


        for(int i=0; i<n; i++){//for connected components
            if(color[i] == -1){//unvisited then apply BFS
                //DFS
                int rang = 0;
                if(!DFS(i, rang, color, graph)) return false;
            }
        }
        return true;
    }
};