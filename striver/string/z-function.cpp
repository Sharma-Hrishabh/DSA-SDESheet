class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.length();
        int m = needle.length();

        for(int i=0;i<n-m+1;i++){
            if(haystack[i]==needle[0]){
                int j = 1;
                while(j<m && haystack[i+j]==needle[j]){
                    j++;
                }
                if(j==m){
                    return i;
                }
            }
        }
        return -1;
    }
};