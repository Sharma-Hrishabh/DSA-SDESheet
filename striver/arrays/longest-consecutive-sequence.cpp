class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_set<int>s;
        int n = nums.size();
        int ans=0;

        for(int i=0;i<n;i++) s.insert(nums[i]);

        for(int i=0;i<n;i++){
            int key=nums[i];

            if(s.find(key-1)==s.end()){
                while(s.find(key+1)!=s.end()) key++;
            
            ans=max(ans,key+1-nums[i]);
            }
            
        }
        return ans;
    }
};