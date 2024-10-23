class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& preq) {
        int n=numCourses;
        unordered_map<int,vector<int>>adj;
        vector<int>indeg(n,0);
        for(int i=0;i<preq.size();i++){
            adj[preq[i][1]].push_back(preq[i][0]);
            indeg[preq[i][0]]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(!indeg[i]){
                q.push(i);
            }
        }
        vector<int> topo;
        while(!q.empty()){
            int node = q.front();
            topo.push_back(node);
            q.pop();
            for(auto it:adj[node]){
                indeg[it]--;
                if(indeg[it]==0){
                    q.push(it);
                }
            }
        }
        if(topo.size()==n){
            return topo;        
        }else{
            return {};
        }
    }
};