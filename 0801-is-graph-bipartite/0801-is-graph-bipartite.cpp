class Solution {
public:
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
                //BFS
                queue<int> q;
                q.push(i); 
                color[i] = 0; //node 0 is colored with 0 color
                while(q.size() > 0){
                    int node = q.front();

                    q.pop();

                    for(auto it: graph[node]){
                        if(color[it] == -1){ //not colored or not visited
                            color[it] = !color[node]; //coloring with diff color
                            q.push(it);
                        }else{
                            //already colored

                            if(color[it] == color[node]) return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};