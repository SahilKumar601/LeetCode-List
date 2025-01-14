class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& a, vector<int>& b) {
        int n = a.size();
        int m = b.size();
        unordered_set<int>seen;
        int common_count=0;
        vector<int>result;
        for(int i=0;i<n;i++){
            if(a[i]==b[i]){
                common_count++;
            }
             if (seen.count(a[i]) || seen.count(b[i])) {
                if (a[i] == b[i]) {
                    common_count++;
                } else {
                    if (seen.count(a[i])) {
                        common_count++;
                    }
                    if (seen.count(b[i])) {
                        common_count++;
                    }
                }
            }
            seen.insert(a[i]);
            seen.insert(b[i]);
            result.push_back(common_count);
        }
        return result;
    }
};