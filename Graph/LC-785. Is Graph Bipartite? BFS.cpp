class Solution {
private:
    bool res = true;
    void bfs(vector<vector<int>>& graph, vector<int>& vis, int start){
        queue<int> q;
        vis[start] = 0;
        q.push(start);
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                int node = q.front();
                q.pop();
                for(auto& it: graph[node]){
                    if(vis[it] == -1){
                        if(vis[node] == 0) vis[it] = 1;
                        else vis[it] = 0;
                        q.push(it);
                    }
                    else{
                        if(vis[node] == vis[it]){
                            res = false;
                            return;
                        }
                    }
                }
            }
        }
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, -1);
        for(int i = 0; i < n; i++){
            if(vis[i] == -1){
                bfs(graph, vis, i);
                if(!res) return false;
            }
        }
        return res;
    }
};