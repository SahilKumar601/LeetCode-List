class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        int op=0;
        vector<int> result;
        for(int i=0;i<n;i++){
            op^=nums[i];
        }
        int m = ((1<<maximumBit)-1);
        for(int i=0;i<n;i++){
            int k = op ^ m;
            result.push_back(k);
            op = op ^ nums[n-i-1];
        }
        return result;
    }
};