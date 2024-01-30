/* O(N*2^N)
// Approach: Iterative Cascading
1 2 3

_
_ 1
_ 1 2 12
_ 1 2 12 3 13 23 123
*/


class Solution {
public:
    
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        int n = nums.size();

        ans.push_back({});
        
        for(int i=0;i<n;i++){
            //defined to keep the size of ans constant for the loop
            vector<vector<int>>tempAns;
            for(int j= 0 ;j<ans.size();j++){
                vector<int>t = ans[j];
                t.push_back(nums[i]);
                tempAns.push_back(t);
            }
            for(int k=0;k<tempAns.size();k++) ans.push_back(tempAns[k]);
        }
        return ans;
    }
};

// O(2^N)
// Approach-1: Simple backtrack approach

class Solution {
public:
    
    void solve(vector<int>&nums,vector<vector<int>>&ans,vector<int>temp,int index,int n){
        if(index>=n) {
            ans.push_back(temp);
            return;
        }

            temp.push_back(nums[index]);
            solve(nums,ans,temp,index+1,n);
            temp.pop_back();
            solve(nums,ans,temp,index+1,n);
        
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        // generating subset is like getting all size of combinations, can be done by backtracking
        vector<vector<int>>ans;
        solve(nums,ans,{},0,nums.size());
        return ans;
    }
};


// Approach: Iterative Backtracking
class Solution {
public:
    
    void solve(vector<int>&nums,vector<vector<int>>&ans,vector<int>temp,int index,int n,int k){
        if(index==k) {
            ans.push_back(temp);
            return;
        }
        
        for(int i=index;i<n;i++){
            temp.push_back(nums[i]);
            solve(nums,ans,temp,i+1,n,k);
            temp.pop_back();
        }

        
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        // generating subset is like getting all size of combinations, can be done by backtracking
        vector<vector<int>>ans;
        int n = nums.size();
        for(int i=0;i<n+1;i++) solve(nums,ans,{},0,n,i);
        return ans;
    }
};

/*
Approach-2: Bitmasking
O(N*2^N)
S(N*2^N)

The idea is to generate all binary numbers from 0 to 2^n-1 and use these numbers as bitmask to generate the subsets.

*/
class Solution {
public:
    
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        int n = nums.size();

        for(int i=0;i<pow(2,n);i++){
            vector<int>temp;
            // in the gererated binary number, 1 means include the element and 0 means exclude the element, so iterate through that to check if jth bit is set or not
            for(int j=0;j<n;j++){
             if(i & 1<<j) temp.push_back(nums[j]);
         }
         ans.push_back(temp);   
        }
        
        return ans;
    }
};