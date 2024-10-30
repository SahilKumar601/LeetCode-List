class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> lis(n,1);
        vector<int> lds(n,1);

        for(int i=0;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(nums[j]<nums[i]){
                    lis[i] = max(lis[i],1+lis[j]);
                }
            }
        }

        for(int i = n-1;i>=0;i--){
            for(int j=i+1;j<n;j++){
                if(nums[i]>nums[j]){
                    lds[i]=max(lds[i],1+lds[j]);
                }
            }
        }

        int result = n;
        for(int i=0;i<n;i++){
            if(lis[i]>1 && lds[i]>1){
                result = min(result,(n-lis[i]-lds[i]+1));
            }
        }
        return result;
        
    }
};