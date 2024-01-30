#include<iostream>
#include<vector>
using namespace std;
    bool isValid(int s,int e, vector<int>&res,int start[],int end[]){
        
        for(int i=0;i<res.size();i++){
            if(s>=start[res[i]] && s<=end[res[i]]) return false;
            if(e>=start[res[i]] && e<=end[res[i]]) return false;
            if(s==end[res[i]] || e==start[res[i]]) return false;
            
        }
        return true;
    }
    
    int solve(int start[],int end[],int n,vector<int>&res,int idx){
        if(idx==n) {
         return res.size();   
        }
        
        if(isValid(start[idx],end[idx],res,start,end)){
            
           res.push_back(idx);
           int x = solve(start,end,n,res,idx+1);
           
           res.pop_back();
           int y = solve(start,end,n,res,idx+1);
           
           if(x>y) res.push_back(idx);

        }
        
        return solve(start,end,n,res,idx+1);
        
        
    }
    
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<int>res;
        return solve(start,end,n,res,0);
        
        
        
        
    }


    int main() {
        int n;
        n=6;
        int start[]={1,3,0,5,8,5};
        int end[]={2,4,6,7,9,9};
        cout<<maxMeetings(start,end,n);
        return 0;
    }