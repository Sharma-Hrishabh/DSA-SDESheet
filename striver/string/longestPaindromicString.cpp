#include<iostream>
#include<vector>
using namespace std;

class Solution1 {
public:
    string expand(string s,int l, int r){
        //if(s=="" || l>r ) return 0;
        while(l>=0 && r<s.length() && s[l]==s[r]){
            l--;
            r++;
        }
        return s.substr(l+1,r-l-1);
    }
    
    string longestPalindrome(string s) {
        
        int n = s.length();
        int start=0,end=0;
        string ans="";
        int maxL=0;
        for(int i=0;i<n;i++){  
            string odd = expand(s,i,i);
            string even = expand(s,i,i+1);
            
            if(odd.length()>even.length()){
                if(odd.length()>maxL){
                    maxL = odd.length();
                    ans = odd;
                }
            }
            else{
                if(even.length()>maxL){
                    maxL = even.length();
                    ans = even;
                }
            }
            
        }
        
        return ans;
    }
};




class Solution {
public:    
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool> > dp(n,vector<bool>(n,false));

        //mark for 1
        for(int i=0;i<n;i++) dp[i][i]=true;

        //mark for 2
        int maxLen=0;
        int start=0;
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]){
                dp[i][i+1]=true;
                maxLen=2;
                start=i;
            }
        }

        //if(n==1) return s.substr(0,1);
        // if(n==2) return s.substr(0,2);

        // since dp is wroking by checking if i+1 & j-1 is palindrome or not, so fill dp fpr less length first
        for(int k=3;k<=n;k++){
            for(int i=0;i<n-k+1;i++){
                // start at i and check for every length
                int j = i+k-1;
                if(dp[i+1][j-1] && s[i]==s[j]) {
                    dp[i][j]=true;
                    if(k>maxLen){
                        maxLen=k;
                        start=i;
                    }
                }
            }
        }

        if(maxLen==0) return s.substr(0,1);
        return s.substr(start,maxLen);

    }
};

int main(){
    Solution s;
    // cout<<s.longestPalindrome("babad")<<endl;
    // cout<<s.longestPalindrome("cbbd")<<endl;
    cout<<s.longestPalindrome("a")<<endl;
    cout<<s.longestPalindrome("aa")<<endl;
    // cout<<s.longestPalindrome("ac")<<endl;
    // cout<<s.longestPalindrome("bb")<<endl;
    // cout<<s.longestPalindrome("ccc")<<endl;
    // cout<<s.longestPalindrome("abacdfgdcaba")<<endl;
    // cout<<s.longestPalindrome("forgeeksskeegfor")<<endl;
    // cout<<s.longestPalindrome("abaaba")<<endl;
    // cout<<s.longestPalindrome("abababa")<<endl;
    // cout<<s.longestPalindrome("abcbabcbabcba")<<endl;

}