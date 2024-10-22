class Solution {
public:
    void bfs(int ptr,vector<int>& vis,unordered_map<int,vector<int>> adj){
        vis[ptr]=1;
        queue<int> q;
        q.push(ptr);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it:adj[node]){
                if(!vis[it]){
                    vis[it]=1;
                    q.push(it);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int m = isConnected[0].size();
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
                bfs(i,vis,mp);
                count++;
            }
        }
        return count;
    }
};