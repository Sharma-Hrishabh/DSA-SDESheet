class Solition{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        
        if(n>m) return kthElement(arr2,arr1,m,n,k);
        // suppose the 2nd list has 6 elements and k is 7 os you cant pick just 0 element so low needs to be adjused and atlease 1
        int low = max(0,k-m);
        // suppose k is 3 and n is 2 so you cant pick 3 elements from 2 so high needs to be adjusted and atmost n
        int high = min(k,n);
        
        while(low<=high){
            int mid1 = (high+low)/2;
            int mid2 = k-mid1;
            
            int l1 = mid1==0 ? INT_MIN: arr1[mid1-1];
            int l2 = mid2==0 ? INT_MIN: arr2[mid2-1];
            int r1 = mid1==n ? INT_MAX: arr1[mid1];
            int r2 = mid2==m ? INT_MAX: arr2[mid2];
            
            if(l1<=r2 && l2<=r1){
                return max(l1,l2);
            }
            else if(l1>r2) high=mid1-1;
            else low = mid1+1;
    
        }
        
       return 0; 
    }
};