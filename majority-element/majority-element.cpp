class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int major = nums[0];      
        int count = 1;
        for(int i=0;i<n;i++){
            if(count == 0){
                count++;
                major = nums[i];
            }
            if(major == nums[i]){
                count++;
            }else {
                count--;
            }
        }
        return major;
    }
};