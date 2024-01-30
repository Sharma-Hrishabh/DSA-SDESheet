#include<iostream>
using namespace std;
class Solution {
public:

    void solve(string s, string &ans,int l,int r,int start){
        // base case
        if(l>r) return;

        while(s[l]==' ' && l<=r) l++;

        
        if(l>r) return;

        int i=l;
        while(s[i]!=' ' && i<=r){
            i++;
        }

        solve(s,ans,i,r,start);

        if(l!=start) ans = ans + s.substr(l,i-l)+" ";
        else ans = ans + s.substr(l,i-l);
        
    }


    string reverseWords(string s) {
        string ans="";
        
        int r=s.size()-1;
        while(s[r]==' '){
            r--;
        } 

        int start = 0;
        while(s[start]==' '){
            start++;
        }

        solve(s,ans,0,r,start);
        return ans;
    }
};

int main(){
    Solution s;
    string s1 = "F R  I   E    N     D      S      ";
    string ans=s.reverseWords(s1);
    replace(ans.begin(),ans.end(),' ','*');
    cout<<ans<<endl;
    cout<<s1.size()<<endl;
    return 0;}