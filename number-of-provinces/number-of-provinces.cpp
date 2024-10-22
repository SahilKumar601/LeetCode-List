class Solution {
public:
    void dfs(int ptr,vector<int>& vis,unordered_map<int,vector<int>> adj){
        vis[ptr]=1;
        for(auto it:adj[ptr]){
            if(!vis[it]){
                dfs(it,vis,adj);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int m = isConnected.size();
        vector<int> vis(n,0);
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isConnected[i][j]==1){
                    mp[i].push_back(j);
                    mp[j].push_back(i);
                }
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,vis,mp);
                count++;
            }
        }
        return count;
    }
};