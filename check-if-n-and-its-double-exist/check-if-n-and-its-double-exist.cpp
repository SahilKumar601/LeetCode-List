class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        for(int i=0;i<n;i++){
            int half = arr[i]*2;
            if(mp.find(half)!=mp.end()){
                mp[arr[i]]--;
                if(mp[half]>=1){
                    return true;
                }
                mp[arr[i]]++;
            }
        }
        return false;
    }
};