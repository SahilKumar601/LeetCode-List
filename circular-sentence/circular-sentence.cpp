class Solution {
public:
    bool isCircularSentence(string sen) {
        int n = sen.length();
        vector<string> words;  
        stringstream ss(sen);
        string t;
        while(ss>>t){
            words.push_back(t);
        }
        if(sen[0] != sen[n-1]){
            return false;
        }
        for(int i=1;i<words.size();i++){
            string lastword = words[i-1];
            string nextword = words[i];
            if(lastword[lastword.length()-1]!=nextword[0]){
                return false;
            }
        }
        return true;
    }   
};