class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        unordered_map<int,int> mp;
        int n = grid.size();
        for(int i=1;i<=n*n;i++){
            mp[i]=0;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                mp[grid[i][j]]++;
            }
        }
        vector<int> result;
        for(auto it:mp){
            if(it.second>1){
                result.push_back(it.first);
            }
        }
        for(auto it:mp){
            if(it.second==0){
                result.push_back(it.first);
            }
        }
        return result;
    }
};