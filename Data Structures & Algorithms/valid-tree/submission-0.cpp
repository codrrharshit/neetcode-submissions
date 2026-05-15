class Solution {
public:
     vector<int> parent;
    
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    bool unionSet(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px == py) return false; // cycle detected
        parent[px] = py;
        return true;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
         if (edges.size() != n - 1) return false;

        parent.resize(n);
        for (int i = 0; i < n; i++) parent[i] = i;

        for (auto& edge : edges) {
            if (!unionSet(edge[0], edge[1])) return false;
        }

        return true; // no cycle and exactly n-1 edges → connected and acyclic
    }
};
