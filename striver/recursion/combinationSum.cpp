class Solution {
public:
    void solve(vector<int>& candidates, vector<vector<int>>&ans, int target,vector<int>temp,int sum){
        if(sum==target){
            sort(temp.begin(),temp.end());
            ans.push_back(temp);
            return;
        }
        if(sum>target) return;

        for(int i=0;i<candidates.size();i++){
            temp.push_back(candidates[i]);
            solve(candidates,ans,target,temp,sum+candidates[i]);
            temp.pop_back();
        }       

    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        int sum=0;
        solve( candidates,ans,target,{},sum);
        sort(ans.begin(),ans.end());
        ans.erase(unique(ans.begin(),ans.end()),ans.end());
        return ans;
    }
};