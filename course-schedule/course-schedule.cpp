class Solution {
public:
    bool canFinish(int N, vector<vector<int>>& preq) {
        vector<int> adj[N];
        vector<int> indeg(N);

        for(int i=0;i<preq.size();i++){
            adj[preq[i][0]].push_back(preq[i][1]);
            indeg[preq[i][1]]++;
        }

        queue<int> q;
        for(int i=0;i<N;i++){
            if(indeg[i]==0){
                q.push(i);
            }
        }
        vector<int> top;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            top.push_back(node);
            for(auto it:adj[node]){
                indeg[it]--;
                if(indeg[it]==0){
                    q.push(it);
                }
            }
        }
        return top.size()==N ? true : false;
    }
};