//O(N2^N)
class Solution {
public:
    
    bool isPalindrome(string &s,int start,int end){
        while(start<end){
            if(s[start++]!=s[end--]) return false;
        }
        
        return true;
    }
    
    void solve(vector<vector<string>>&res,string &s, int start, vector<string>&curr){
        if(start>=s.length()) res.push_back(curr);
        

        // start at an start index and  push the end iteratively. During the interation if a substr is palindrome then the start of next slice will start after the end of first, so do a dfs.
        for(int i=start;i<s.length();i++){
            if(isPalindrome(s,start,i)){
                curr.push_back(s.substr(start,i-start+1));
                solve(res,s,i+1,curr);
                curr.pop_back();
            }
        }
        
    }
        
    vector<vector<string>> partition(string s) {
        vector<vector<string>>res;
        vector<string>curr;
        
        solve(res,s,0,curr);
        
        return res;
        
    }
};



//DP

class Solution {
public:
    
    void solve(vector<vector<string>>&res,string &s, int start, vector<string>&curr,vector<vector<bool>>&dp){
        if(start>=s.length()) res.push_back(curr);
        
        for(int i=start;i<s.length();i++){
            // first check start and end are same , and if the length is less than 2 or the substring between start and end is palindrome.
            if(s[start]==s[i] && (i-start<=2 || dp[start+1][i-1])){
                dp[start][i]=true;
                curr.push_back(s.substr(start,i-start+1));
                solve(res,s,i+1,curr,dp);
                curr.pop_back();
            }
        }
        
    }
        
    vector<vector<string>> partition(string s) {
        vector<vector<string>>res;
        vector<string>curr;
        vector<vector<bool>>dp (s.length(),vector<bool>(s.length(),false));
        
        solve(res,s,0,curr,dp);
        
        return res;
        
    }
};