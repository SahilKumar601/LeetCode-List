class Solution {
public:
    vector<string> removeSubfolders(vector<string>& str) {
        unordered_set<string> st(begin(str), end(str));
        vector<string> result;
        for(string& currFolder : str) {
            bool isSubFolder = false;
            string tempFolder = currFolder;
            while(!currFolder.empty()) {
                size_t position = currFolder.find_last_of('/');
                currFolder = currFolder.substr(0, position);
                if(st.find(currFolder) != st.end()) {
                    isSubFolder = true;
                    break;
                }
            }
            if(!isSubFolder) {
                result.push_back(tempFolder);
            }

        }

        return result;
    }
};