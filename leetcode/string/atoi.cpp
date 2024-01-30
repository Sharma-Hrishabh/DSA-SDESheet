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

        if(isdigit(s[start])==false) return 0;
        

        
        
        // chcek end
        int end=start;
        
        for(int i=start;i<s.length();i++){
            if(isdigit(s[i])==true) end=i;
            else break;
        }
        
        

        
        //remove 0s
        for(int i=start;i<s.length();i++){
            start=i;
            if(s[i]!='0') break;        
         }
        
        cout<<start<<"-"<<end<<endl;
      
        int ans=0;

        int l = end-start+1;

        
        string temp = s.substr(start,l);
        string temp2 = to_string(INT_MAX);
        // 2147483647
        //string temp3 = to_string(INT_MAX+1);
        cout<<temp<<" "<<temp2<<endl;
        //if(neg && temp>temp3) return 0;
        if(!neg ){ 
           // if(temp.length() >= temp2.length() && temp>temp2) return INT_MAX;
            if(temp.length() > temp2.length()) return INT_MAX;
            if(temp.length() == temp2.length() && temp>temp2) return INT_MAX;
        }
        else {
           // if(temp.length() >= temp2.length() && temp>temp2) return INT_MIN;
            if(temp.length() > temp2.length()) return INT_MIN;
            if(temp.length() == temp2.length() && temp>temp2) return INT_MIN;
        }
        
        for(int i=end;i>=start;i--){
            //cout<<ans<<"$$\n";
            ans += (s[i]-'0') * pow(10,abs(end-i));
            
           // cout<<ans<<"$$\n";
        }
        if (neg) ans *=-1;
        return ans;

    }
};