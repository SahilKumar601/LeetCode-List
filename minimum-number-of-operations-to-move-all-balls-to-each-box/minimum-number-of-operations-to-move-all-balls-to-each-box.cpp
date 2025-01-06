class Solution {
public:
    vector<int> minOperations(string s) {
        int n = s.length();
        vector<int>result(n,0);
        int cumVal=0;
        int cumSum=0;

        for(int i=0;i<n;i++){
            result[i]+=cumSum;

            cumVal+=s[i] == '0' ? 0:1;
            cumSum+=cumVal;
        }
        cumVal=0;
        cumSum=0;
        for(int i=n-1;i>=0;i--){
            result[i]+=cumSum;

            cumVal+=s[i] == '0' ? 0:1;
            cumSum+=cumVal;
        }
        return result;
    }
};