class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i=0,j=n-1;
        if(n==2){
            return (j-i)*min(height[j],height[i]);
        }
        int max_area = 0;
        while(i<j){
            int area = (j-i)*min(height[j],height[i]);
            max_area = max(area,max_area);
            if(height[i]<height[j]){
                i++;
            }else{
                j--;
            }
        }
        return max_area;
    }  
};