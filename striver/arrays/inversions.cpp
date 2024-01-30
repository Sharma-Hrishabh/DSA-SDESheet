#include<iostream>
using namespace std;
class Solution {
public:

    void count(vector<int>& nums, int l, int mid, int r, int &ans){
        // int n = mid-l+1;
        // int m = r-mid;

        int s1 = l;
        int s2 = mid+1;

        if(nums[mid]<=nums[mid+1]) return;


        while(s1<=mid && s2<=r){
            if(nums[s1]<=nums[s2]){
                s1++;
            }
            else{
                ans++;
                int index = s2;
                int temp = nums[index];
                while(index!=s1){
                    nums[index]=nums[index-1];
                    index--;
                }

                nums[index]=temp;

                s1++;
                s2++;
                mid++;
            }


        }
        return;
    }


    void mergeDivide(vector<int>& nums, int l, int r, int &ans){
        if(l==r) return;
        int mid = l + (r-l)/2;

        mergeDivide(nums,l,mid,ans);
        mergeDivide(nums,mid+1,r,ans);
        count(nums,l,mid,r,ans);
        return;

    }


    int globalInversions(vector<int>& nums, int n){
        int ans=0;
        mergeDivide(nums,0,n-1,ans);
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
        cout<<a<<"-"<<b<<endl;
        return a == b;
    }
};

int main(){
    Solution s;
    vector<int> nums;
    // = {1,0,2};
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(0);
    cout<<s.isIdealPermutation(nums);
}