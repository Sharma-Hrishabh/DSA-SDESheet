// Input: s = "A man, a plan, a canal: Panama"
// Output: true
// Explanation: "amanaplanacanalpanama" is a palindrome.


class Solution {
public:
    bool isPalindrome(string s) {

    int i=0;
    int j=s.length()-1;
    while(i<j){
    
        int temp=0;
        //check if no is alphanumeric and skips those
        if(!iswalnum(s[i])) {i++;temp=1;}
        if(!iswalnum(s[j])) {j--;temp=1;}
        if(temp!=0) continue;
    
        if(isupper(s[i])) s[i]+=32;
        if(isupper(s[j])) s[j]+=32;
        
        
        if(s[i]!=s[j]) return false;
        

        i++;
        j--;
    }
       return true; 
    }
};