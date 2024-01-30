#include<iostream>
#include<vector>
using namespace std;
// class Solution {
// public:

//     bool binarySearch(vector<vector<int> >& matrix, int target, int row, int l, int r){
//         while(l<=r){
//             int mid = (l+r)/2;

//             if(matrix[row][mid]==target) return true;
//             else if(target>matrix[row][mid]) return binarySearch(matrix,target,row,mid+1,r);
//             else return binarySearch(matrix,target,row,l,mid-1);
//         }
//         return false;

//     }

//     bool binarySearchRow(vector<vector<int> >& matrix, int target,int l, int r){
        
//         while(l<=r){
//             int midRow = (l+r)/2;

//             if(target<matrix[midRow][0]) return binarySearchRow(matrix,target,l,midRow-1);
//             else if(target>matrix[midRow][matrix[midRow].size()-1]) return binarySearchRow(matrix,target,midRow+1,r);
//             else return binarySearch(matrix,target,midRow,0,matrix[midRow].size()-1);
        
//         }
//         return false;
//     }

//     bool searchMatrix(vector<vector<int> >& matrix, int target) {
//         return binarySearchRow(matrix,target,0,matrix.size()-1);
//     }
// };



class Solution {
public:

    bool binarySearch(vector<int>&nums, int low, int high, int target){
        if(high==low && nums[low]==target) return true;
        if(high>low){
            int mid = low + (high-low)/2;
            if(nums[mid]==target) return true;
            if(target>nums[mid]) return binarySearch(nums,mid+1,high,target);
            else binarySearch(nums,low, mid, target);
        }


        return false;
    }


    bool binarySearchRow(vector<vector<int> >& matrix, int target, int lowR, int highR, int n){

        if(highR==lowR) return binarySearch(matrix[lowR],0,n-1,target);


        if(highR>lowR) {

            int midR = lowR + (highR-lowR)/2;

            if(target<=matrix[midR][n-1] && target>=matrix[midR][0]) return binarySearch(matrix[midR],0,n-1,target);
            else if(target>matrix[midR][n-1]){
                //search next rows
                return binarySearchRow(matrix,target,midR+1,highR,n);
            }
            else{
                //search prev rows
                return binarySearchRow(matrix,target,lowR,midR,n);
            }
        }


        return false;
    }

 


    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        return binarySearchRow(matrix,target,0,matrix.size()-1,n);
    }
};

int main(){
    Solution s;
    vector<vector<int> > matrix;
    vector<int>a;
    a.push_back(1);
    a.push_back(3);
    a.push_back(5);
    a.push_back(7);
    matrix.push_back(a);
    vector<int>b;
    b.push_back(10);
    b.push_back(11);
    b.push_back(16);
    b.push_back(20);
    matrix.push_back(b);
    vector<int>c;
    c.push_back(23);
    c.push_back(30);
    c.push_back(34);
    c.push_back(60);
    matrix.push_back(c);

    bool ans=s.searchMatrix(matrix,13);
    cout<<ans;
    return 0;
}