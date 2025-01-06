class Solution {
public:
    vector<int> minOperations(string s) {
        vector<int> vec;
        vector<int> result;
        int n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                vec.push_back(i);
            }
        }
        int k=0;
        for(int i=0;i<n;i++){
            int moves=0;
            for(int j=0;j<vec.size();j++){
                if(i==vec[j]){
                    continue;
                }else{
                    moves+=abs(i-vec[j]);
                }
            }
            result.push_back(moves);
        }
        return result;
    }
};