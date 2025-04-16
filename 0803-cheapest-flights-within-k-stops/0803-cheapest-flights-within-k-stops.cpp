class Solution {
public:
    //dijkstra
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n, vector<pair<int,int>>(0));

        for(int i=0; i<flights.size(); i++){
            int a = flights[i][0];
            int b = flights[i][1];
            int w = flights[i][2];

            adj[a].push_back({b, w});
        }

        vector<int> distance(n, 1e9);

        priority_queue<pair<int,pair<int, int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int, int>>>> pq;
        //************important************
        //here we store as {stops, {distance, node}}
        //because when we are storing as distance, due to minimum distance we do not consider further path, but the path may lead to destination with required number of stops.
        //we have seen this in a testcase
        //n = 4, flights = [[0,1,1],[0,2,5],[1,2,1],[2,3,1]], src = 0, dst = 3, k = 1


        pq.push({1, {0, src}});  //{stop, {distance, node}}  stops = number_of_nodes -2 (number_of_nodes - start_node - end_node) 
        distance[src] = 0;
        

        int mini = INT_MAX;
        while(pq.size() > 0){
           int stop = pq.top().first;
           int dist = pq.top().second.first;
           int node = pq.top().second.second;

           if(node == dst && stop <= k+2){
                mini = min(mini, dist);
                // there can be many ways to reach destination in which stops <=k+2
                //but we need cheapest
                //so, we take minimum of all paths.
           }

           pq.pop();

           for(auto it : adj[node]){
                int adjNode = it.first;
                int adjDist = it.second;

                if(distance[adjNode] > adjDist + dist){
                    distance[adjNode] = adjDist + dist;
                    pq.push({stop+1, {adjDist + dist,adjNode}}); //increase the stop by 1
                }
           }
        }
        if(mini == INT_MAX) return -1;
        return mini;
    }
};