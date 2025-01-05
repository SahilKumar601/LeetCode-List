class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = shifts.size();
        int m = s.length();

        vector<int> res(m,0);
        for(int i=0;i<n;i++){
            int start = shifts[i][0];
            int end = shifts[i][1];
            int inc;
            shifts[i][2] == 1 ? inc=1 : inc = -1;
            res[start]+=inc;
            if(end<m-1){
                res[end+1]-=inc;
            }
        }
        for(int i=1;i<m;i++){
            res[i]=res[i-1] + res[i];
        }
        for(int i=0;i<m;i++){
            cout<<res[i]<<" ";
        }
        string result;
        for(int i=0;i<m;i++){
            int shift = res[i] % 26;
            if(shift<26){
                shift+=26;
            }
            s[i]=(((s[i]-'a')+shift)%26)+'a';
        }

        return s;
    }
};