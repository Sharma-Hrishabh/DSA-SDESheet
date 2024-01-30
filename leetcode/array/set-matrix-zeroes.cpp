// Brute Force: O(n^2) & S(n)

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int>I;
        set<int>J;
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    I.insert(i);
                    J.insert(j);
                }
            }
        }
        
        
        
        for(auto itr = I.begin();itr!=I.end();itr++){
            for(int j=0;j<n;j++){
                matrix[*itr][j]=0;
            }
        }
        
        for(auto itr = J.begin();itr!=J.end();itr++){
            for(int i=0;i<m;i++){
                matrix[i][*itr]=0;
            }
        }
        
    }
};

// We can take two arrays and mark the element as 0 if it is 0 in the matrix's row or column in above approach.

// But we can do it in O(1) space by using the first row and column of the matrix itself as the arrays we used in the above approach.

// This approach is called as "Space Optimized" approach.

// We will be using the first row and first column of the matrix as the arrays we used in the above approach.

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
