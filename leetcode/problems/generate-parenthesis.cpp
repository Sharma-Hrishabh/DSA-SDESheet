class Solution {
public:
    void solve(int n, int openings , int closings , string temp, vector<string> &ans){
        if(temp.size()==2*n){
            ans.push_back(temp);
            return ;
        }
        
        if(openings<n){
           
            solve(n,openings+1,closings,temp+'(',ans);
        }
        
        if(closings<openings){
            
            solve(n,openings,closings+1,temp+')',ans);
        }
          return ;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve(n,0,0,"",ans);
        return ans;
    }
};


class Solution {
public:
    void solve(int n, int openings , int closings , string temp, vector<string> &ans){
        if(temp.size()==2*n){
            ans.push_back(temp);
            return ;
        }
        
        if(openings<n){
             temp+='(';
            solve(n,openings+1,closings,temp,ans);
            temp.pop_back();
        }
        
        if(closings<openings){
             temp+=')';
            solve(n,openings,closings+1,temp,ans);
            temp.pop_back();
        }
        
        
          return ;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve(n,0,0,"",ans);
        return ans;
    }
};


class Solution {
public:

    void getBrackets(int n,vector<string>&ans,int i,string &pattern,int &balance){
        if(pattern.length() == 2*n) {
            if(balance==0) ans.push_back(pattern);
            return;
        }
        //give open bracket && if invalid return
        pattern.push_back('(');
        balance++;
        if(balance>=0) getBrackets(n,ans,i+1,pattern,balance);
        //backtrack
        balance--;
        pattern.pop_back();
        //give close bracket && if invalid return
        pattern.push_back(')');
        balance--;
        if(balance>=0) getBrackets(n,ans,i+1,pattern,balance);
        balance++;
        pattern.pop_back();
        
    }
    
    
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string pattern;
        int balance=0;
        int i=0;
        
        getBrackets(n,ans,i,pattern,balance);
        
        return ans;
        
    }
};