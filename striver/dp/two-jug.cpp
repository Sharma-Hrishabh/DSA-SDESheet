class Solution {
public:

bool visited[1000000][1000000]={false};


    bool solve(int j1,int c1,int j2, int c2, int t){
        if(j1==t || j2==t) return true;

        //try all possible ways
        if(!visited[j1][j1]==false){
                visited[j1][j2]=true;
            bool exp1 = solve(0,c1,j2,c2,t) || solve(j1,c1,0,c2,t) || solve(c1,c1,j2,c2,t) || solve(j1,c1,c2,c2,t); 
            bool exp2 = solve(j1 + min(j2,c1-j1),c1,j2-min(j2,c1-j1),c2,t) || solve(j1-min(j1,c2-j2),c1,j2+min(j1,c2-j2),c2,t);
            return exp1 || exp2;
        }

        return false;

    }

    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        return solve(0,jug1Capacity,0,jug2Capacity,targetCapacity);
    }
};