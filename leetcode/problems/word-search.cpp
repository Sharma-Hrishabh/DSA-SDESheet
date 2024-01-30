class Solution {
public:
    
    bool solve(vector<vector<char>>& board, string word,int i, int j, int m, int n,int index){
        if(index==word.size()) return true;
        if(i<0 || j<0 || i>=m || j>=n) return false;
        if(board[i][j]!=word[index]) return false;
        
        board[i][j] = '0';
      
        bool res = solve(board,word,i-1,j,m,n,index+1) || solve(board,word,i+1,j,m,n,index+1) || solve(board,word,i,j-1,m,n,index+1) || solve(board,word,i,j+1,m,n,index+1);
        
        board[i][j]=word[index];
        
        return res;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(); 
        int n = board[0].size();
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(word[0]==board[i][j] && solve(board,word,i,j,m,n,0)) return true;
            }
        }
        
        return false;
        
    }
};