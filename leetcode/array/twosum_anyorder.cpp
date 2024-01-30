// O(nlogn),O(1)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //  nums = [2,7,11,15], target = 9
        vector<int>ans;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int i=0;
        int j=n-1;
        while(i<j){
            if(nums[i]+nums[j]>target) j--;
            else if(nums[i]+nums[j]<target) i++;
            else {  
                ans.push_back(i);
                ans.push_back(j);
            }
        }            
    }
};


// O(logn),O(1)
int binarySearch(vector<int>nums,int start,int end,int key)
{
    int mid = (start+end)/2;

    if(nums[mid]==key) return mid;

    if(start>=end) return -1;

    if(key>nums[mid]) binarySearch(nums,start,mid-1);
    else binarySearch(nums,mid+1,end);
}


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //  nums = [2,7,11,15], target = 9
        vector<int>ans;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n && nums[i]<target;i++){
            
                int key = target-nums[i];
                int index = binarySearch(nums,i,n-1,key);
                if(index!=-1) {
                    ans.push_back(i);
                    ans.push_back(index);
                    break;
                }
        }
        return ans;
    }
};