class Solution {
public:
    int findPivot(vector<int> nums,int n){
        int l=0,h=n-1;
        while(l<h){
            int mid = l+(h-l)/2;
            if(nums[mid]>nums[h]){
                l = mid+1;
            }else{
                h=mid;   
            }
        }
        return h;
    }
    int binarySearch(int l,int h,vector<int> nums,int target){
        while(l<=h){
            int mid = l+(h-l)/2;
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid]>target){
                h = mid-1;
            }else{
                l = mid+1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int pivot = findPivot(nums,n);
        cout<<nums[pivot]<<endl;
        int idx = binarySearch(0,pivot-1,nums,target);
        if(idx!=-1){
            return idx;
        }
        idx = binarySearch(pivot,n-1,nums,target);
        return idx;
    }
};