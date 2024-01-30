#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool isValid(vector<string>&s,int n,int row, int col){
           for (int i = 0; i < s.size(); i++) {
                if (s[i][col] == 'Q')
                    return false;
            }
            int i = row, j = col;
            while (i >= 0 && j >= 0)
                if (s[i--][j--] == 'Q')
                    return false;
            i = row, j = col;
            while (i >= 0 && j < s.size())
                if (s[i--][j++] == 'Q')
                    return false;
            return true;
    }
    void solve(vector<vector<string> >&ans,int n, int row ,vector<string>s){
        
        if(row==n){
            ans.push_back(s);
            return;            
        }

        for(int i=0;i<n;i++){
            if(isValid(s,n,row,i)){
                s[row][i]='Q';
                solve(ans,n,row+1,s);
                s[row][i]='.';
            }

        }
        
        return;

    }

    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> >ans;
        vector<string>s(n,std::string(n,'.'));
            
        solve(ans,n,0,s);
        
        return ans;      
    }
};

int main(){
    Solution s;
    vector<vector<string> >ans = s.solveNQueens(4);
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<endl;
        }
        cout<<endl;
    }
    return 0;
}