// recursion
class Solution {
public:
    vector<int>temp;
    void solve(vector<int>& candidates,int index, int sum, int target,vector<vector<int>>& ans,vector<int>& temp){
        if(index>=candidates.size()) return;
        
        if(candidates[index]+sum == target) {
            temp.push_back(candidates[index]);
            ans.push_back(temp);
            temp.pop_back();
            return;
        }
        
        if(candidates[index]+sum < target){
            //we have a choice to include or exclue the element
            //include 
            temp.push_back(candidates[index]);
            solve(candidates,index,sum+candidates[index],target,ans,temp);
            temp.pop_back();
            //exlcude
            solve(candidates,index+1,sum,target,ans,temp);
        }
        else{
            //since the array is sorted, we can't include the element as it will increase the sum greater than target
            //start from next index
            //solve(candidates,index+1,sum,target,ans,temp);
        }

    }
    
    
    vector<vector<int>> combinationSum(vector<int>& candidates,int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        sort(candidates.begin(),candidates.end());
        solve(candidates,0,0,target,ans,temp);
        return ans;   
    }
};



//simple backtrack w/o sort

class Solution {
public:
   void solve(vector<int> &cand, vector<vector<int>> &ans, vector<int> v, int i, int sum, int target){
        if(i>=cand.size()){
            return;
        }
        
        if(sum==target){
            ans.push_back(v);
            return;
        }     
        
        if(sum>target){
            return;
        }

        v.push_back(cand[i]); 
        solve(cand,ans,v, i, sum + cand[i], target);
        v.pop_back(); 
        solve(cand,ans,v, i + 1, sum, target);
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& cand, int tar) {
        vector<vector<int>> ans;
        solve(cand, ans,{}, 0, 0,tar);
            
        return ans;
    }
};
