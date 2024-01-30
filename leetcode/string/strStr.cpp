// Input: haystack = "hello", needle = "ll"
// Output: 2

class Solution {
public:
    int strStr(string haystack, string needle) {
        int l = haystack.length();
        int m = needle.length();

        if(m>l) return -1;
        int ans=-1;
        for(int i=0;i<l;i++){
            int k=0;
            if(haystack[i]==needle[k]){
                ans=i;
                for(int j=k+1;j<m && i+k<l;j++){
                    
                    if(haystack[i+j]!=needle[j]) {ans=-1;break;}
                }
            }
            if(ans!=-1) break;
        }
        return ans;

    }
};


class Solution {
public:
    int strStr(string haystack, string needle) {
        int l = haystack.length();
        int m = needle.length();

        if(m>l) return -1;
        int ans=-1;
        for(int i=0;i<l;i++){
            int j=0;
            int match=0;
            if(haystack[i]==needle[j]){
                ans=i;
                while(j<m && i+j<l){
                    if(haystack[i+j]!=needle[j]) {
                        ans=-1;
                        break;
                    }
                    match++;
                    j++;
                }    
            }
            if(ans!=-1&& match!=m) ans = -1;
            if(ans!=-1 && match==m) {break;}
        }
        return ans;

    }
};
