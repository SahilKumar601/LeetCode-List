class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int l=0,h=n-1;
        if(n==1){
            return nums[0];
        }
        if(nums[l]!=nums[l+1])return nums[l];
        if(nums[h]!=nums[h-1])return nums[h];
        
        while(l<=h){
            int mid = l+(h-l)/2;
            if(nums[mid]!= nums[mid-1] && nums[mid]!= nums[mid+1]){
                return nums[mid];
            }
            if(mid%2==0){
                if(nums[mid-1]==nums[mid]){
                    h=mid-1;
                }else{
                    l=mid+1;
                }
            }else{
                if(nums[mid]==nums[mid-1]){
                    l=mid+1;
                }else{
                    h=mid-1;
                }
            }
        }
        return -1;
    }
};