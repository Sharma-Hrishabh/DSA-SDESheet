class Solution {
public:
    bool rowCheck(vector<vector<char>>& board){
        
        for(int i=0;i<9;i++)
        {
            unordered_set<char>s;
            for(int j=0;j<9;j++){
            
                if(board[i][j]=='.') continue;                
                if(s.find(board[i][j])!=s.end()) {return false;}
                else s.insert(board[i][j]);

            }
        }
        return true;

    }

    bool colCheck(vector<vector<char>>& board){

        for(int i=0;i<9;i++)
        {
            unordered_set<char>s;
            for(int j=0;j<9;j++){
            
                if(board[j][i]=='.') continue;

                if(s.find(board[j][i])!=s.end()) return false;
                s.insert(board[j][i]);

            }
        }
        return true;

    }


    bool boxCheck(vector<vector<char>>& board){
       // unordered_set<char>s;
        for(int i=0;i<9;i+=3){
            for(int j=0;j<9;j+=3){

                unordered_set<char>s;
                for(int x=i;x<i+3;x++){
                    
                    for(int y=j;y<j+3;y++){

                    
                        if(board[x][y]=='.') continue;

                        if(s.find(board[x][y])!=s.end()) {return false;}
                            s.insert(board[x][y]);
                    }


                }

            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        return (rowCheck(board) && colCheck(board) && boxCheck(board));
    }
    
    
};