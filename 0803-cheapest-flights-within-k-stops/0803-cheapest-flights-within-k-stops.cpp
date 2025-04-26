class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int, int>> adj[n];
        for (auto it : flights) {
            adj[it[0]].push_back({it[1], it[2]});
        }
        
        queue<tuple<int, int, int>> q; 
        vector<int> dist(n, 1e9);
        dist[src] = 0;
        
        q.push({0, src, 0}); 
        
        while (!q.empty()) {
            auto [steps, node, cost] = q.front();
            q.pop();
            
            if (steps > k) continue; 
            
            for (auto &[adjNode, edW] : adj[node]) {
                if (cost + edW < dist[adjNode]) {
                    dist[adjNode] = cost + edW;
                    q.push({steps + 1, adjNode, cost + edW});
                }
            }
        }
        
        return dist[dst] == 1e9 ? -1 : dist[dst];
    }
};