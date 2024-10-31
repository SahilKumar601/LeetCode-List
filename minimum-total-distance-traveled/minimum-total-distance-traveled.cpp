class Solution {
public:
    long long solve(int pos,int f_pos,vector<int>& robot,vector<int>& fac_pos,vector<vector<long long>>& t){
        if(pos>=robot.size()){
            return 0;
        }
        if(f_pos>=fac_pos.size()){
            return 1e12;
        }
        if(t[pos][f_pos]!=-1){
            return t[pos][f_pos];
        }
        long long take = abs(robot[pos] - fac_pos[f_pos]) + solve(pos+1,f_pos+1,robot,fac_pos,t);
        long long leave = solve(pos,f_pos+1,robot,fac_pos,t);

        return t[pos][f_pos] = min(take,leave);
    }
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        int n = robot.size();
        sort(robot.begin(),robot.end());
        sort(factory.begin(),factory.end());
        vector<int> fact_pos;
        for(int i=0;i<factory.size();i++){
            int pos = factory[i][0];
            int limits = factory[i][1];

            for(int j=0;j<limits;j++){
                fact_pos.push_back(pos);
            }
        }
        vector<vector<long long>> t(n+1,vector<long long>(fact_pos.size()+1,-1));
        return solve(0,0,robot,fact_pos,t);
    }
};