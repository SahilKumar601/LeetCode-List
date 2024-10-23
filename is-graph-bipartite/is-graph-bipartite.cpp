class Solution {
public:
    bool dfs(int ptr,vector<int>& color,vector<int>& vis,unordered_map<int,vector<int>> adj){
        vis[ptr]=1;
        for(auto it:adj[ptr]){
            if(!vis[it]){
                color[it]=!color[ptr];
                if(dfs(it,color,vis,adj)==false){
                    return false;
                }
            }else if(color[it]==color[ptr]){
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<n;i++){
            for(int j=0;j<graph[i].size();j++){
                mp[i].push_back(graph[i][j]);
                // mp[i].push_back(graph[i][i])
            }
        }
        vector<int> color(n,0);
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                if(!dfs(i,color,vis,mp)){
                    return false;
                }
            }
        }
        return true;
    }
};