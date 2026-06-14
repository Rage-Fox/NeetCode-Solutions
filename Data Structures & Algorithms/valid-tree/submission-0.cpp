class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        // a tree is an undirected graph with no cycles
        // all the nodes are connected as one component
        if (edges.size() > n - 1) {
            return false;
        }
        vector<vector<int>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        unordered_set<int> visit;
        queue<pair<int, int>> q;
        q.push({0, -1});  // {current node, parent node}
        visit.insert(0);
        while (!q.empty()) {
            auto [node, parent] = q.front();
            q.pop();
            for (int neigh : adj[node]) {
                if (neigh == parent) {
                    continue;
                }
                if (visit.count(neigh)) {
                    return false;
                }
                visit.insert(neigh);
                q.push({neigh, node});
            }
        }
        return visit.size() == n;
    }
};
