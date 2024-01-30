#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    bool isValid(int i, int j, int m, int n){
        if(i<0) return false;
        if(i>=m) return false;
        if(j<0) return false;
        if(j>=n) return false;
        return true;
    }
    void bfs(vector<vector<char> >& board,vector<vector<int> >& touchBoundary,int m,int n, int i, int j){
        queue<pair<int,int> >q;
        q.push(make_pair(i,j));
        touchBoundary[i][j]=1;

        while(!q.empty()){
            pair<int,int> node = q.front();
            int row = node.first;
            int col = node.second;
            q.pop();

            int dR[4] = {-1,0,1,0};
            int dC[4] = {0,1,0,-1};
            for(int i=0;i<4;i++){
                int newRow = row+dR[i];
                int newCol = col+dC[i];
                if(isValid(newRow,newCol,m,n)&& board[newRow][newCol]=='O' && !touchBoundary[newRow][newCol]){
                    touchBoundary[newRow][newCol]=1;
                    q.push(make_pair(newRow,newCol));
                }
            }
        }

    }

    void solve(vector<vector<char> >& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int> >touchBoundary(m,vector<int>(n,0));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 || i==m-1 || j==0 || j==n-1){
                    if(board[i][j]=='O') {
                        cout<<"starting from:"<<i<<" "<<j<<endl;
                        bfs(board,touchBoundary,m,n,i,j);
                    }
                }
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O') {
                    if(touchBoundary[i][j]==0){
                        board[i][j]='X';

                    }
                }
            }
        }


    }
};

int main(){
    vector<vector<char> >board;
    vector<char>temp1;
    temp1.push_back('X');
    temp1.push_back('X');
    temp1.push_back('X');
    temp1.push_back('X');
    board.push_back(temp1);
    
    vector<char>temp2;
    temp2.push_back('X');
    temp2.push_back('O');
    temp2.push_back('O');
    temp2.push_back('X');
    board.push_back(temp2);

    
    
    vector<char>temp3;
    temp3.push_back('X');
    temp3.push_back('X');
    temp3.push_back('O');
    temp3.push_back('X');
    board.push_back(temp3);


    vector<char>temp4;
    temp4.push_back('X');
    temp4.push_back('O');
    temp4.push_back('X');
    temp4.push_back('X');
    board.push_back(temp4);

    // vector<char>temp6;
    // temp6.push_back('O');
    // temp6.push_back('O');
    // temp6.push_back('X');
    // temp6.push_back('O');
    // temp6.push_back('O');
    // temp6.push_back('O');
    // board.push_back(temp6);

    Solution s;
    s.solve(board);
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[0].size();j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}