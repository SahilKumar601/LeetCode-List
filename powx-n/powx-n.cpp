class Solution {
public:
    double myPow(double x, int n) {
        if(n==0) return 1.0;
        if(x==1) return 1.0;
        if(x==0) return 0.0;
        if(x==-1 && n%2==0) return 1.0;
        if(x==-1 && n%2!=0) return -1.0;
        double ans = 1;
        long form = n;
        if(n<0){
            x=1/x;
            form = -(form);
        }
        while(form >0){
            if(form % 2 == 1){
                ans *= x;
            }
            x *= x;
            form /= 2;
        }
        return ans;
    }
};