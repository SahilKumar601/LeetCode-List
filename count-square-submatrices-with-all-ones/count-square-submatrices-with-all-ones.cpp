class Solution {
public:
    int t[301][301];
    int solve(int i,int j,vector<vector<int>> &mat){
        if(i>=mat.size() || j>=mat[0].size()){
            return 0;
        }
        if(mat[i][j]==0){
            return t[i][j]=0;
        }
        if(t[i][j]!=-1){
            return t[i][j];
        }
        int right = solve(i,j+1,mat);
        int dia = solve(i+1,j+1,mat);
        int down = solve(i+1,j,mat);

        return t[i][j]=1+min({right,dia,down});
    }
    int countSquares(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int count=0;
        memset(t,-1,sizeof(t));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==1){
                    count+=solve(i,j,mat);
                }
            }
        }
        return count;
    }
};