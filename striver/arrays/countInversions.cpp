//latest
class Solution {
public:

    void merge(vector<int>& nums, int l, int mid, int r, int &ans){
        // int n = mid-l+1;
        // int m = r-mid;
        vector<int>temp;
        int left = l;
        int right = mid+1;

        while(left<=mid && right<=r){
            if(nums[left]<=nums[right]){
                temp.push_back(nums[left]);
                left++;
            }
            else{
                temp.push_back(nums[right]);
                ans += mid-left+1;
                right++;
            }
        }

        while(left<=mid){
            temp.push_back(nums[left]);
            left++;
        }
        while(right<=r){
            temp.push_back(nums[right]);
            right++;
        }

        //copy temp to real array
        for(int i=l;i<=r;i++){
            nums[i]=temp[i-l];
        }

     
    }


    void mergeSort(vector<int>& nums, int l, int r, int &ans){
        if(l==r) return;
       
        int mid = l + (r-l)/2;

        mergeSort(nums,l,mid,ans);
        mergeSort(nums,mid+1,r,ans);
        merge(nums,l,mid,r,ans);
        return;

    }


    int globalInversions(vector<int>& nums, int n){
        int ans=0;
        mergeSort(nums,0,n-1,ans);
        return ans;
    }

    int localInversions(vector<int>& nums, int n){
        int ans=0;
        for(int i=0;i<=n-2;i++){
            if(nums[i]>nums[i+1]) {
                ans++;
            }
        }
        return ans;

    }

    bool isIdealPermutation(vector<int>& nums) {
        int n = nums.size();
        int b = localInversions(nums,n);
        int a = globalInversions(nums,n);
        //cout<<a<<"-"<<b<<endl;
        return a == b;
    }
};



#include <iostream>
using namespace std;
void merge(long long *arr,int l,int mid, int r,long long &sum){
    int i=l;
    int j=mid+1;

    int n = mid-l+1;
    int m = r-mid;

    for(;i<=mid;i++){
        for(;j<=r;j++){
            if(arr[i]>arr[j]){
                sum++;
            }
        }
        j=mid+1;
    }
}

void mergeSort(long long *arr,int l, int r,long long &sum){
    if(l>=r) return;

    int mid = l + (r-l)/2;

    mergeSort(arr,l,mid,sum);
    mergeSort(arr,mid+1,r,sum);

    merge(arr,l,mid,r,sum);

}

long long getInversions(long long *arr, int n){
    // Write your code here.
    long long  sum=0;
    mergeSort(arr,0,n-1,sum);
    return sum;
}

int main(){

    long long arr[5]={2,5,1,3,4};

    cout<<getInversions(arr,5);
    return 0;
}



// Correct


// C++ program to Count
// Inversions in an array
// using Merge Sort
#include <bits/stdc++.h>
using namespace std;
  
int _mergeSort(int arr[], int temp[], int left, int right);
int merge(int arr[], int temp[], int left, int mid,
          int right);
  
// This function sorts the
// input array and returns the
// number of inversions in the array
int mergeSort(int arr[], int array_size)
{
    int temp[array_size];
    return _mergeSort(arr, temp, 0, array_size - 1);
}
  
// An auxiliary recursive function
// that sorts the input array and
// returns the number of inversions in the array.
int _mergeSort(int arr[], int temp[], int left, int right)
{
    int mid, inv_count = 0;
    if (right > left) {
        // Divide the array into two parts and
        // call _mergeSortAndCountInv()
        // for each of the parts
        mid = (right + left) / 2;
  
        // Inversion count will be sum of
        // inversions in left-part, right-part
        // and number of inversions in merging
        inv_count += _mergeSort(arr, temp, left, mid);
        inv_count += _mergeSort(arr, temp, mid + 1, right);
  
        // Merge the two parts
        inv_count += merge(arr, temp, left, mid + 1, right);
    }
    return inv_count;
}
  
// This function merges two sorted arrays
// and returns inversion count in the arrays.
int merge(int arr[], int temp[], int left, int mid,
          int right)
{
    int i, j, k;
    int inv_count = 0;
  
    i = left;
    j = mid;
    k = left;
    while ((i <= mid - 1) && (j <= right)) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
  
            // this is tricky -- see above
            // explanation/diagram for merge()
            inv_count = inv_count + (mid - i);
        }
    }
  
    // Copy the remaining elements of left subarray
    // (if there are any) to temp
    while (i <= mid - 1)
        temp[k++] = arr[i++];
  
    // Copy the remaining elements of right subarray
    // (if there are any) to temp
    while (j <= right)
        temp[k++] = arr[j++];
  
    // Copy back the merged elements to original array
    for (i = left; i <= right; i++)
        arr[i] = temp[i];
  
    return inv_count;
}
  
// Driver code
int main()
{
    int arr[] = { 1, 20, 6, 4, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int ans = mergeSort(arr, n);
    cout << " Number of inversions are " << ans;
    return 0;
}
  


