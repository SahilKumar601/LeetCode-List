class Solution {
public:
    string compressedString(string word) {
        string result;
        int n = word.size();
        int i=0;
        while(i<n){
            char curr= word[i];
            int count=1;
            for(int j=i+1;j<n;j++){
                if(curr == word[j]){
                    count++;
                    i++;
                }
                else{
                    break;
                }
            }
            while(count/9 > 0){
                result+= "9"+string(1,curr);
                count-=9;
            }
            if(count>0)
                result+=to_string(count)+curr;
            i++;
        }
        return result;
    }
};