class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<vector<int>>ans;
        for(int i=0;i<n-3;i++){
            for(int j=i+1;j<n-2;j++){
                int l = j+1;
                int r = n-1;
                
                while(l<r){
                    long long currSum = nums[i]+nums[j];
                    currSum+=+nums[l]+nums[r];
                    if(currSum==(long long)target){
                        vector<int>temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[l]);
                        temp.push_back(nums[r]);
                        ans.push_back(temp);
                        l++;
                        r--;
                    }
                    else if(currSum<(long long)target) l++;
                    else r--;
                    
                }
                
            }
        }
        
        sort( ans.begin(), ans.end() );
        ans.erase( unique( ans.begin(), ans.end() ), ans.end() );
        return ans;
    }
};