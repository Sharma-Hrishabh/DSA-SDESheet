/*
Approach-1 Brute Force: O(N^2) time and O(1) space

min(left_max,right_max) - height[i] for a index i will give the amount of water that can be trapped at that index.
to calculate the amount of water that can be trapped at each index, we need to find the left_max and right_max for each index.
which will lead to nested loops.



Appoach-2 Brute Force with O(N) space.

Calclaute prefix and suffix array of height array and then find the min of prefix and suffix array at each index and subtract the height at that index to get the amount of water that can be trapped at that index.
//0,1,0,2,1,0,1,3,2,1,2,1

Prefix 0 1 1 2 2 2 2 3 3 3 3 3
Suffix 3 3 3 3 3 3 3 3 2 2 2 1

min(prefix[i],suffix[i]) - height[i]


Approach-3: Using 2 pointers

Remember we will move the lef tpointer when there is some value in right greater than the left pointer and vice versa.
So instead of  taking min of left_max and right_max, we can take one of them accordingly which will be automatically the min of both.
O(N)
S(1)
*/

class Solution {
public:
    int trap(vector<int>& height) {
        
        int n = height.size(); 
        int left=0; int right=n-1;
        int res=0;
        int maxleft=0, maxright=0;
        
        while(left<=right){
            
            if(height[left]<=height[right]){

                if(height[left]>=maxleft) maxleft=height[left];
                else res+=maxleft-height[left];
                
                left++;
            }
            else{

                if(height[right]>=maxright) maxright= height[right];
                else res+=maxright-height[right];
                
                right--;
            }
        }
        return res;
    }
};