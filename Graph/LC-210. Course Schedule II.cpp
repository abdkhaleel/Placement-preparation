class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto& it: prerequisites){
            adj[it[1]].emplace_back(it[0]);
        }

        vector<int> indegree(numCourses, 0);
        for(int i = 0; i < numCourses; i++){
            for(auto& it: adj[i]){
                indegree[it]++;
            }
        }

        stack<int> st;
        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0){
                st.push(i);
            }
        }

        vector<int> topo;
        while(!st.empty()){
            int node = st.top();
            st.pop();
            topo.emplace_back(node);
            for(auto& it: adj[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    st.push(it);
                }
            }
        }
        if(numCourses == topo.size()) return topo;
        return {};
    }
};