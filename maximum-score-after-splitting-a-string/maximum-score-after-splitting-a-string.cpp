class Solution {
public:
    int maxScore(string s) {
        int n = s.length();
        int result = 0;
        int zeros=0,ones=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                ones++;
            }else{
                zeros++;
            }
        }
        if(ones==0){
            return zeros/2;
        }
        int score =0;
        int left=0,right=ones;
        for(int i=0;i<n-1;i++){
            if(s[i]=='0'){
                left++;
            }else if(s[i]=='1' && right>0){
                right--;
            }
            score = left+right;
            result = max(result,score);
        }
        return result;
    }
};