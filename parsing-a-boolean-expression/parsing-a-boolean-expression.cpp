class Solution {
public:
    bool solve(char op,vector<char> vec){
        // cout<<" "<<vec.size()<<" ";
        // return 1;
        if(op=='|'){
            for(int i=0;i<vec.size();i++){
                if(vec[i]=='t'){
                    return true;
                }
            }
            return false;
        }
        else if(op=='&'){
            for(int i=0;i<vec.size();i++){
                if(vec[i]=='f'){
                    return false;
                }
            }
            return true;
        }
        else{
           if(vec[0]=='t'){
                return false;
           }else{
                return true;
           }
        }
    }
    bool parseBoolExpr(string exp) {
        stack<char> st;
        int n = exp.length();
        for(int i=0;i<n;i++){
            if(exp[i]==',') continue;
            st.push(exp[i]);
            if(exp[i]==')'){
                vector<char> vec;
                while(st.top()!='('){
                    if(st.top()=='t' || st.top() == 'f'){
                        vec.push_back(st.top());
                    }
                    st.pop();
                }
                st.pop();
                if(solve(st.top(),vec)){
                    st.pop();
                    st.push('t');
                }else{
                    st.pop();
                    st.push('f');
                }
                
            }
        }
        return st.top() == 't' ? true : false; 
    }
};