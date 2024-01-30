// Input: s = "    4193 with words 23"
// Output: 4193
class Solution {
public:
    int myAtoi(string s) {
        bool neg = false;
        int start=0;
        
      
        
        //remove whitespaces
        for(int i=0;i<s.length();i++){
            start=i;
            if(s[i]!=' ') break;        
         }
        
        //sign
        if(s[start]=='-') {start++;neg=true;}
        else if(s[start]=='+') start++;
        else{
            
        }

        //if after removing whitespaces and sign, the first character is not a digit, return 0
        if(isdigit(s[start])==false) return 0;
        

        
        
        //set the end of number
        int end=start;
        
        for(int i=start;i<s.length();i++){
            if(isdigit(s[i])==true) end=i;
            else break;
        }
        
        //remove head zeroes
        for(int i=start;i<s.length();i++){
            start=i;
            if(s[i]!='0') break;        
         }
        
        cout<<start<<"-"<<end<<endl;
      
        int ans=0;

        int l = end-start+1;

        
        string temp = s.substr(start,l);
        string temp2 = to_string(INT_MAX);

        cout<<temp<<" "<<temp2<<endl;
        if(!neg ){ 
            if(temp.length() > temp2.length()) return INT_MAX;
            if(temp.length() == temp2.length() && temp>temp2) return INT_MAX;
        }
        else {
            if(temp.length() > temp2.length()) return INT_MIN;
            if(temp.length() == temp2.length() && temp>temp2) return INT_MIN;
        }
        
        for(int i=end;i>=start;i--){
            ans += (s[i]-'0') * pow(10,abs(end-i));
        }
        if (neg) ans *=-1;
        return ans;

    }
};