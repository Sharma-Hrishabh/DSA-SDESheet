/* Approach:1: Start with O(N) space approach by keeping a count array of size N+1 and find first missing positive number


 Extra:

If the array contained only positive no.
6 5 9 3 1  
1 2 3 4 5

-6 5 -9 3 -1  
 1 2  3 4  5

We can multiply the number at index i with -1.
After this in the next iteration, the index of first no which will be non negative  can give first missing number.

But this approach will not work if the array contains both positive and negative numbers.


Approach:2: O(1) space approach:

The idea is to keep a ith number at ith index(starting from 1)
So, we can swap the ith number with the (number at index i) -1.

*/
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        
        for(int i=0;i<n;i++){
            while(nums[i]>=1 && nums[i]<=n && nums[i] != nums[nums[i]-1]){
                swap(nums[i],nums[nums[i]-1]);  // number 3 goes to index 2
            }
        }
        
        
        for(int i=0;i<n;i++){
            if(i+1 != nums[i]) return i+1;
        }
        return n+1;
    }
};