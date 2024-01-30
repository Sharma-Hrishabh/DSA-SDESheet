// Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
// Output: [1,2,3,4,8,12,11,10,9,5,6,7]

class Solution {
public:
    
    string giveDir(string dir,int& maxRight,int& maxLeft,int& maxUp,int& maxDown,int i,int j){
        if(i==maxUp && j==maxRight && dir=="right"){
            maxUp = i+1;
            return "down";
        }
        else if(i==maxDown && j==maxLeft && dir=="left"){
            maxDown = i-1;
            return "up";
        }
        else if(i==maxUp && j==maxLeft && dir=="up"){
            maxLeft = j+1;
            return "right";
        }
        else if(i==maxDown && j==maxRight && dir=="down"){
            maxRight = j-1;
            return "left";
        }        
        
        else return dir;
        
    }
    
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        vector<int> ans;
        int m = matrix.size(); //3
        int n = matrix[0].size(); //4
        int i=0;
        int j=0;
        int count = m*n;
        int maxRight=n-1; //3
        int maxLeft=0; 
        int maxUp=0;
        int maxDown=m-1; //2
        string dir="right";
            while(count--){
                ans.push_back(matrix[i][j]);
                // decide if any change of direction is there
                dir =  giveDir(dir,maxRight,maxLeft,maxUp,maxDown,i,j);
                if(dir=="up") i--;
                else if(dir=="down") i++;
                else if(dir=="right") j++;
                else j--;
            }
        
        return ans;
    }
};