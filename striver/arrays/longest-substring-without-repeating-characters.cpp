
// O(N)
class Solution {
public:
    int max(int a,int b){
        return a>b?a:b;
    }
    
    int lengthOfLongestSubstring(string s) {
        vector<int>mp(256,-1);
        //keeps track of last occurence of character

        int l=0;
        int ans=0;
        for(int r=0;r<s.length();r++){
            //if a char already exists and its within range(l has come fowrard) then jump the l to its last occur + 1
            if(mp[s[r]]!=-1) l = max(l,mp[s[r]]+1);
            
            // include the new char occurence and also update already existing char occurence
            mp[s[r]]=r;
            
            // check the substring length
            ans = max(ans,r-l+1);
        }
        return ans;
    }
};