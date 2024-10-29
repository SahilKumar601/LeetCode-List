class Solution {
public:
    int m=0,n=0;
    int t[1001][1001];
    int solve(int row,int col,vector<vector<int>>& grid){
        if(row>=m || col>=n || row<0 || col<0){
            return 0;
        }
        if(t[row][col]!=-1){
            return t[row][col];
        }
        int curr = grid[row][col];
        int row_mov[]={-1,0,1};
        int col_mov[]={1,1,1};
        int ans=0;
        for(int i=0;i<3;i++){
            int row_ele = row+row_mov[i];
            int col_ele = col+col_mov[i];
            if(row_ele>=m || col_ele>=n || row_ele<0 || col_ele<0){
                continue;
            }
            else if(grid[row_ele][col_ele]>curr){
                ans=max(ans,1+solve(row_ele,col_ele,grid));
            }
        }
        return t[row][col] = ans;
    }
    int maxMoves(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int result =0;
        memset(t,-1,sizeof(t));
        for(int i=0;i<m;i++){
            int count = solve(i,0,grid);
            result = max(count,result);
        }
        return result;
    }   
};