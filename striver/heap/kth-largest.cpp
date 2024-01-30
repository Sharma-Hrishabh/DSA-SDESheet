class Solution {
public:
    int findKthLargest(vector<int>& nums, int k)
    {
        priority_queue<int,vector<int>,greater<int>>minheap;
        for(int i =0;i<k;i++)
        {
            minheap.push(nums[i]);
        }
        for(int i =k;i<nums.size();i++)
        {
            // we have to find kth largest from bottom, so why put small element on top, push greater element sonly to adjust from bottom
            if(minheap.top()<nums[i])
            {
                minheap.pop();
                minheap.push(nums[i]);
            }
        }
        int ans =minheap.top();
        return ans;
    }
};