//O(nlogn),O(1)
//sort & compare

//O(N),O(1)
class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int>vs(26,0);
        vector<int>vt(26,0);
        for(int i=0;i<s.length();i++) vs[s[i]-'a']++;
        for(int i=0;i<t.length();i++) vt[t[i]-'a']++;
        for(int i=0;i<26;i++){
            if(vs[i]!=vt[i]) return false;
        }
        return true;
    }
};