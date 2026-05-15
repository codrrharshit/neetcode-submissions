class Solution {
public:
    vector<int>parent;
    int find(int x){
        if(parent[x]==x){
            return x;
        }
        return parent[x]=find(parent[x]);
    }

    void unite(int x,int y){
        if(find(x)==find(y)){
            return ;
        }
        parent[find(x)]=find(y);
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        for(int i=0;i<n;i++) parent[i]=i;

        for(auto &edge:edges){
            int u=edge[0];
            int v=edge[1];
            unite(u,v);
        }

        unordered_set<int>s;
        for(int i=0;i<n;i++){
            s.insert(find(i));
        }

        return s.size();

    }
};
