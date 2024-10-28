class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        unordered_map<int,int> st;
        for(auto it : nums){
            st[it]=0;
        }
        int maxCount=0;
        for(int i=0;i<n;i++){
            long long ptr = nums[i];
            int count=0;
            while(st.find(ptr)!=st.end() && st[ptr]!=1){
                st[ptr]=1;
                count++;
                long long temp = ptr; 
                ptr = temp*temp;
            }
            maxCount=max(count,maxCount);
        }
        return maxCount==1 ? -1 : maxCount;
    }
};