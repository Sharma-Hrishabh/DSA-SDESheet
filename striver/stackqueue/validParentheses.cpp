#include <bits/stdc++.h> 
#include<stack>
using namespace std;

class Solution {
public:

    bool isOpening(char c){
        if(c=='(' ||c=='{' || c=='[') return true;
        return false;
    }

    char matching(char c){
        if(c==')') return '(';
        else if(c=='}') return '{';
        return '[';
    }

    bool isValid(string s) {

        stack<char>b;

        for(int i=0;i<s.length();i++){
            if(isOpening(s[i])) b.push(s[i]);
            else{
                //
                char top = b.top();
                char m = matching(s[i]);
                if(top!=m) return false;
                else{
                    b.pop();
                }
            }

        }

        if(!s.empty()) return false;
        return true;
    }
};

int main(){
    string s = "()";
    Solution *sol = new Solution();
    
    std::cout<<sol->isValid(s);
}