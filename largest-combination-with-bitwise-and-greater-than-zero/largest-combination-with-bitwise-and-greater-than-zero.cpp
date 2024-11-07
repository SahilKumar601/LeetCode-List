class Solution {
public:
    int largestCombination(vector<int>& cand) {
        vector<int> count(24,0);
        int result=0;
        for(int i=0;i<24;i++){
            for(int &nums:cand){
                if((nums & (1<<i))!=0){
                    count[i]++;
                }
            }
            result = max(result,count[i]);
        }
        return result;
    }
};