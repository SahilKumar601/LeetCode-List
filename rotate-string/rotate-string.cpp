class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.length(),m = goal.length();
        if(n!=m){
            return false;
        }
        string sen = s+s;
        int ptr = 0;
        int start = 0;
        for(int i=0;i<sen.length();i++){
            int j=0;
            for(;j<m;j++){
                cout<<goal[j]<<" "<<sen[i+j]<<endl;
                if(goal[j]!=sen[i+j]){
                    break;
                }
            }
            if(j==m){
                return true;
            }
        }
        return false;
    }
};