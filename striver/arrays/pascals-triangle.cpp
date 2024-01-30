class Solution {
public:

    void getPascal(int numRows,vector<vector<int>>&v){
        if(numRows==1){
            vector<int>t;
            t.push_back(1);
            v.push_back(t);

            return;
        }
        // if left most insert
        // if next element add and insert
        // if rightmost insert
        getPascal(numRows-1,v);

        vector<int>t;
        for(int i=0;i<v[numRows-2].size();i++){
            
            if(i==0) {
                t.push_back(v[numRows-2][0]);
                
            }
            if(i<v[numRows-2].size()-1) {
                t.push_back(v[numRows-2][i]+v[numRows-2][i+1]);
            }
            
            if(i==v[numRows-2].size()-1) {
                int last = v[numRows-2][v[numRows-2].size()-1];
                t.push_back(last);
            }

        }
        v.push_back(t);
        return;

    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>v;
        getPascal(numRows,v);

        return v;
    }
};