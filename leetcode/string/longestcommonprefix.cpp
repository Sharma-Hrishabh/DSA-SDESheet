class Solution {
public:

    string helper (string s1, string s2){

        int l = s1.length();
        int m = s2.length();

        string res="";
        for(int i=0;i<min(l,m);i++){
            if(s1[i]!=s2[i]) break;
            res += s1[i];
        }   

        return res;
    }

    string longestCommonPrefix(vector<string>& strs) {
        // finding longestcommonprefix is associate between multiple strings
        string s = strs[0];
        for(int i=1;i<strs.size();i++){
            s = helper(s,strs[i]);
        }
        return s;   
    }
};