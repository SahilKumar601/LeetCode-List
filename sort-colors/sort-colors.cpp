class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero = count(nums.begin(),nums.end(),0);
        int ones = count(nums.begin(),nums.end(),1);
        int twos = count(nums.begin(),nums.end(),2);
        int i=0;
        while(zero>0){
            nums[i]=0;
            i++;
            zero--;
        }
        while(ones>0){
            nums[i]=1;
            i++;
            ones--;
        }
        while(twos>0){
            nums[i]=2;
            i++;
            twos--;
        }
    }
};