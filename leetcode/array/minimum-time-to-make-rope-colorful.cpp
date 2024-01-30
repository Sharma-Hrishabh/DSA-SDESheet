// O(N)
class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.length();
        int ans=0;
        int sum=0;
        for(int i=0;i<n;i++) sum+=neededTime[i];
        
        for(int i=0;i<n-1;){
            int maxTime = neededTime[i];
            int j;
            int flag=0;
            for(j=i+1;j<n && colors[i]==colors[j];j++){
                flag=1;
                maxTime = max(maxTime,neededTime[j]);
            }
            cout<<maxTime<<endl;
            ans+=maxTime;
            //set i
            if(flag==0) i++;
            else i=j;
           
        }
        if(colors[n-2]!=colors[n-1]) ans+=neededTime[n-1];
        
        ans = sum-ans;
        return ans;
    }
    
    
};



class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        // Initalize two pointers i, j.
        int totalTime = 0;
        int i = 0, j = 0;
        
        while (i < neededTime.size() && j < neededTime.size()) {
            int currTotal = 0, currMax = 0;
            
            // Find all the balloons having the same color as the 
            // balloon indexed at i, record the total removal time 
            // and the maximum removal time.
            while (j < neededTime.size() && colors[i] == colors[j]) {
                currTotal += neededTime[j];
                currMax = max(currMax, neededTime[j]);
                j++;
            }
            
            // Once we reach the end of the current group, add the cost of 
            // this group to total_time, and reset two pointers.
            totalTime += currTotal - currMax;
            i = j;
        }
        return totalTime;
    }
};