#include<iostream>
#include<string>

using namespace std;
    string normalize(string s){
        string ans="";
        int n=s.length();
        int start=0;
        int len=0;
        s+=".";
        n++;
        for(int i=0;i<n;i++){
            if(s[i]!='.'){
                len++;
            }
            else{
                string t = s.substr(start,len);
                int m = stoi(t);
                string u = to_string(m);
                if(ans=="") ans=ans+u;
                else ans=ans+"."+u;
                
                
                len=0;
                start=i+1;
            }
        }
        return ans;

    }


int main(){
    string s;
    s="1.001.320.01";
    cout<<normalize(s);
    return 0;
}