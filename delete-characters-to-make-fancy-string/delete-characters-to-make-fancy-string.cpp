class Solution {
public:
    string makeFancyString(string s) {
        int n = s.length();
        string result = "";
        char prev = s[0];
        int count =1;
        result+=prev;
        for(int i=1;i<n;i++){
            if(s[i]==prev){
                count++;
                prev=s[i];
                if(count!=3){
                    result+=s[i];
                }
                else if(count==3){
                    count-=1;
                    continue;
                }
            }else{
                count=1;
                result+=s[i];
                prev=s[i];
            }
        }
        return result;
    }
};