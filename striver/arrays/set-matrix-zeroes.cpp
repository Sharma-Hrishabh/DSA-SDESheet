// O(N*M)
// S(N+M)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        int row[m];
        int col[n];
        memset(row,0,m);
        memset(col,0,n);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    row[i]=1;
                    col[j]=1;
                }
            }
        }


        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(row[i]==1 || col[j]==1) matrix[i][j]=0;
            }
        }

    }
};


// Keep the dummy array as first col and first row
// Now at a point one 0 can be covered and identified from row and col. Suppose any col is 0, it will be marked in corresposning row. So keep a track of any row element is 0 or not.
// O(N*M)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        bool row = false;

        for(int i=0;i<m;i++){
            if(matrix[i][0]==0){
                row = true;
            }

            for(int j=1;j<n;j++){
                if(matrix[i][j]==0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }


        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=1;j--){
                if(matrix[i][0]==0 || matrix[0][j]==0){
                    matrix[i][j] = 0;
                }
            }
            if(row) matrix[i][0] = 0;
        }


    }
};
