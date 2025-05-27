class Solution {
private:
    vector<int> parent;
    int find(int x){
        if(parent[x] != x) return find(parent[x]);
        return parent[x];
    }

    void unionSet(int x, int y){
        int px = find(x);
        int py = find(y);
        if(py != px) parent[px] = py;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        parent.resize(n);
        for(int i = 0; i < n; i++) parent[i] = i;
        for(int u = 0; u < n; u++){
            for(int v: graph[u]){
                if(find(u) == find(v)) return false;
                unionSet(graph[u][0], v);
            }
        }
        return true;
    }
};