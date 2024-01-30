#include<bits/stdc++.h>

int solve(int row, int n, int lastDone,vector<vector<int>>&points){
    if(row==0){
        if(lastDone==0) return max(points[0][1],points[0][2]);
        if(lastDone==1) return max(points[0][0],points[0][2]);
        if(lastDone==2) return max(points[0][0],points[0][1]);
    }

    int maxPoint=INT_MIN;

    for(int i=0;i<3;i++){

      if (lastDone != i) {
          int act = points[row][i] + solve(row-1,n,i,points);
          if(act>maxPoint) maxPoint=act;
      }
    }

    return maxPoint;


}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    int row = n-1;
    int lastDone = 3;

    return solve(row,n,lastDone,points);

}



//memoization

#include<bits/stdc++.h>

int solve(int row, int n, int lastDone,vector<vector<int>>&points,vector<vector<int>>&dp){
    if(row==0){
        if(lastDone==0) return max(points[0][1],points[0][2]);
        if(lastDone==1) return max(points[0][0],points[0][2]);
        if(lastDone==2) return max(points[0][0],points[0][1]);
    }


    if(dp[row][lastDone]!=-1) return dp[row][lastDone];


    int maxPoint=0;


    for(int i=0;i<3;i++){
      if (lastDone != i) {
        int point;
        point = points[row][i] + solve(row - 1, n, i, points,dp);
        maxPoint = max(point,maxPoint);  
        
      }
    }

    if(dp[row][lastDone]==-1) dp[row][lastDone]=maxPoint;

    return maxPoint;


}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.

    vector<vector<int>>dp(n,vector<int>(4,-1));
    int row = n-1;
    int lastDone = 3;

    return solve(row,n,lastDone,points,dp);

}
//dp

#include<bits/stdc++.h>

int solve(int n,vector<vector<int>>&points,vector<vector<int>>&dp){
    
    dp[0][0]=max(points[0][1],points[0][2]);
    dp[0][1]=max(points[0][0],points[0][2]);
    dp[0][2]=max(points[0][0],points[0][1]);
    dp[0][3]=max( points[0][0],max(points[0][1],points[0][2]));



    for(int row=1;row<n;row++){
        for(int i=0;i<4;i++){
            int maxPoint = INT_MIN;
            for(int j=0;j<3;j++){

                if(i!=j){
                    //give me points for this activity when done on this day, take dp from previous day when done on any activity
                    int point = points[row][j]+dp[row-1][j];
                    maxPoint = max(maxPoint,point);

                }
            }
            dp[row][i]=maxPoint;
        }

    }

    return dp[n-1][3];

}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.

    // dp here is for max points for each day and last done activity
    vector<vector<int>>dp(n,vector<int>(4,-1));
    int row = 0;


    return solve(n,points,dp);

}