class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix[0].size();
        
        // rotate by main diagnoal - transpose
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                int temp = matrix[i][j];
                matrix[i][j]=matrix[j][i];
                matrix[j][i]=temp;
            }
        }
        //rotate by mid column
        int m = floor(n/2);
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++){
                int temp = matrix[i][j];
                matrix[i][j]= matrix[i][n-1-j];
                matrix[i][n-1-j]=temp;
            }
        }
        
    }
};