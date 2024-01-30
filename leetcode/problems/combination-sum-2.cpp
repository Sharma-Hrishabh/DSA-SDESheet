// here recursion is based on choice which index to start from. At every point you have to make choice from the remaining indexed [to the right] which one to pick.

// you will not pick up first index in case of duplicates and end the recursion for remaining duplicates.


class Solution {
public:
    
    void solve(vector<int>& candidates,int i, int target,int sum,vector<int> temp,vector<vector<int>> &ans){
        if(sum>target) return;
        if(sum==target){
            ans.push_back(temp);
        }
      
        if(i>=candidates.size()) return;
        
        //include a index
        for(int it=i;it<candidates.size();it++){
            
            if(it>0 && candidates[it-1]==candidates[it] && it>i) continue;
            
            temp.push_back(candidates[it]);
            solve(candidates,it+1,target,sum+candidates[it],temp,ans);
            temp.pop_back();
            
        }
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>temp;
        vector<vector<int>>ans;
        sort(candidates.begin(),candidates.end());
        solve(candidates,0,target,0,temp,ans);
        return ans;
    }
};