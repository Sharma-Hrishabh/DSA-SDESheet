class Solution {
public:
    bool isPalindrome(int x) {
  
        //negative cant be palindrome
        if(x<0) return false;
        //0 always palindrome
        if(x==0) return true;
        //0 at MSD in reverse cant be palindrome
        if(x%10==0) return false;
        
        
        int ans=0;
        //reverse only half of the number
        while(x>ans){
            int t = x%10;
            x/=10;
            ans = ans*10+t;
        }
        
    return (ans==x || ans/10==x);
    }
};