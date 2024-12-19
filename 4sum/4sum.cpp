class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        set<vector<int>> st;
        sort(nums.begin(),nums.end());
        long long sums=0;
        if(n==4){
            for(int i=0;i<n;i++){
                sums+=nums[i]; 
            }
            if(sums == target){
                return {nums};
            }else{
                return {};
            }
        }
        for(int i=0;i<=n-4;i++){
            for(int j=i+1;j<=n-3;j++){
                int ptr1=j+1,ptr2=n-1;
                long sum = nums[i] + nums[j]; 
                long x = target - sum;
                cout<<sum<<endl;
                while(ptr1<ptr2){
                    long add = nums[ptr1] + nums[ptr2];
                    if(add == x){
                        st.insert({nums[i],nums[j],nums[ptr1],nums[ptr2]});
                        ptr1++;
                        ptr2--;
                    }
                    else if(add<x){
                        ptr1++;
                    }else{
                        ptr2--;
                    }
                }
            }
        }
        vector<vector<int>> result;
        for(auto tri : st){
            result.push_back(tri);
        }
        return result;
    }
};