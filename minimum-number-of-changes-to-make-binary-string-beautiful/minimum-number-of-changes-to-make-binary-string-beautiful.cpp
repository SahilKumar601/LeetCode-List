class Solution {
public:
    int minChanges(string s) {
        int n = s.length();
        char prev = s[0];
        int count = 1;
        int changes = 0;
        for(int i=1;i<n;i++){
            if(s[i]==prev){
                count++;
                continue;
            }
            if(count%2!=0){
                changes++;
                count=0;
            }else{
                count=1;
            }
            prev = s[i];
        }
        return changes;
    }
};