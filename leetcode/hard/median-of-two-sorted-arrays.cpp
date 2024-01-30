// https://takeuforward.org/data-structure/median-of-two-sorted-arrays-of-different-sizes/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        if(n2<n1) return  findMedianSortedArrays(nums2,nums1);
        
        int low = 0;
        int high = n1;
        
        while(low<=high){
            int cut1 = (low+high)/2;
            int cut2 = ((n1+n2+1)/2)-cut1;
            
            int l1 = cut1==0 ? INT_MIN :nums1[cut1-1];
            int l2 = cut2==0 ? INT_MIN : nums2[cut2-1];
            int r1 = cut1 == n1 ? INT_MAX :nums1[cut1];
            int r2 = cut2 == n2 ? INT_MAX : nums2[cut2];
            
            if(l1<=r2 && l2<=r1){
                if((n1+n2)%2==0) {
                    return (max(l1,l2)+min(r1,r2))/2.0;
                }
                else return max(l1,l2);
            }
                else if(l1>r2){
                    high=cut1-1;
                }
                else{
                    low=cut1+1;
                }
            }
        
        return 0.0;
    }
};


/*
// Dry Run
[1,2] [3,4]

n1 = 2
n2 = 2

low = 0
high = 2

cut1 = 1
cut2 = 1

l1 = 1  r1 = 2
l2 = 3  r2 = 4

3<=2  no
so shift 3 to right = increasing cut1 not to pick 3
-----------
low = 2
high = 2

cut1 = 2
cut2 = 0

l1 = 1 2  r1 =  int max
l2 = int min   r2 = 3 4

successful

*/