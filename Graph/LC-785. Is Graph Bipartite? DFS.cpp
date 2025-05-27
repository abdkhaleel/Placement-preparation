class Solution {
private:
    bool res = true;
    void dfs(vector<vector<int>>& graph, vector<int>& vis, int start){
        stack<int> st;
        vis[start] = 0;
        st.push(start);
        while(!st.empty()){
            int node = st.top();
            st.pop();
            for(auto& it: graph[node]){
                if(vis[it] == -1){
                    if(vis[node] == 0) vis[it] = 1;
                    else vis[it] = 0;
                    st.push(it);
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
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, -1);
        for(int i = 0; i < n; i++){
            if(vis[i] == -1){
                dfs(graph, vis, i);
                if(!res) return false;
            }
        }
        return res;
    }
};