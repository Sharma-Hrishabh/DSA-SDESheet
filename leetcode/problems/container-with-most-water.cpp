class Solution {
public:
    int maxArea(vector<int>& height) {
    //start with the longest width and if the next height is greater, shift l and r to the next heght keeping track of max area
        int n = height.size(); 
        int l=0;
        int r=n-1;
        int maxArea=0;
        while(l<r){
            int area = (r-l)*min(height[l],height[r]);
            maxArea = max(maxArea,area);
            if(height[l]<height[r]) l++;
            else r--;
        }    
    return maxArea;
    }
};