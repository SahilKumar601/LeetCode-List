// The easiest solution to this problem is:
// Step 1: Calculate length of "pref"
// Step 2: find substring of "words" from 0 to length of "pref"
// if both match increment count by 1;



class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        
        int count=0;
        int preflen=pref.size();
        
        for(auto i:words){
            if(i.substr(0,preflen) == pref)    
                count++;                       
            
        }
        return count;   
        
    }
};