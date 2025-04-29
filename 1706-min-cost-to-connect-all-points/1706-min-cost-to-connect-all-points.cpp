class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        //first we have to connect each and every node with a distance
        vector<vector<int>> edges;
        for(int i=0; i<points.size(); i++){
            for(int j=i+1; j<points.size(); j++){
                int x1 = points[i][0];
                int y1 = points[i][1];

                int x2 = points[j][0];
                int y2 = points[j][1];

                int distance = abs(x1-x2) + abs(y1-y2);

                edges.push_back({i, j, distance});
            }
        }

            //Now we will create priority queue and visited array but note do not mark visited before while loop
            int n = points.size(); //number of nodes

            vector<vector<pair<int,int>>> adj(n, vector<pair<int,int>> (0));
            for(int i=0; i<edges.size(); i++){
                int u = edges[i][0];
                int v = edges[i][1];
                int w = edges[i][2];

                adj[u].push_back({v, w});
                adj[v].push_back({u, w});
            }
            vector<int> visited(n, 0);

            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

            pq.push({0, 0});
            int sum = 0;
            while(pq.size() > 0){
                int dist  = pq.top().first;
                int node = pq.top().second;
                
                pq.pop();
                if(visited[node] == 1) continue;
                visited[node] = 1;
                sum += dist;

                for(auto it : adj[node]){
                    int adjnode = it.first;
                    int adjdist = it.second;
                    if(!visited[adjnode]){
                        pq.push({adjdist, adjnode});
                    }
                }

            }
        return sum;
    }
};