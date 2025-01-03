class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        long long sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        long long inLoop=0;
        int result=0;
        for(int i=0;i<n-1;i++){
            inLoop+=nums[i];
            if(inLoop >= sum-inLoop){
                result++;
            }
        }
        return result;
    }
};