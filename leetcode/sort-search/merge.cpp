//O(N^2)
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0;
        int j=0;
        while(i<m && j<n){
            if(nums1[i]<=nums2[j]){
                i++;
            }
            else{
                int k=m-1;
                while(k>=i){
                    nums1[k+1]=nums1[k];
                    k--;
                }
                nums1[k+1]=nums2[j];
                j++;
                m++;
                i++;
            }
        }
        
        while(j<n){
            nums1[i]=nums2[j];
            i++;
            j++;
        }
        
    }
};

//O(N+M)
// Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
// Output: [1,2,2,3,5,6]
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m-1;
        int j=n-1;
        int k = m+n-1;
        while(i>=0 && j>=0){
            if(nums1[i]<nums2[j]){
                nums1[k]=nums2[j];
                k--;
                j--;
            }
            else{
                nums1[k]=nums1[i];
                i--;
                k--;
            }
        }
        while(i>=0){
            nums1[k]=nums1[i];
            k--;
            i--;
        }        

        while(j>=0){
            nums1[k]=nums1[j];
            k--;
            j--;
        }        
    }
};

