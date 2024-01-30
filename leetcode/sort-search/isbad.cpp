logo
Explore
Problems
Interview
Contest
Discuss
Store
🔈 LeetCode is hiring! Apply NOW.🔈

Premium
0
0
  Back to Chapter
  First Bad Version

Solution
You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check. Since each version is developed based on the previous version, all the versions after a bad version are also bad.

Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.

You are given an API bool isBadVersion(version) which returns whether version is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.

 

Example 1:

Input: n = 5, bad = 4
Output: 4
Explanation:
call isBadVersion(3) -> false
call isBadVersion(5) -> true
call isBadVersion(4) -> true
Then 4 is the first bad version.
Example 2:

Input: n = 1, bad = 1
Output: 1
 

Constraints:

1 <= bad <= n <= 231 - 1
C++	
1
// The API isBadVersion is defined for you.
2
// bool isBadVersion(int version);
3
​
4
class Solution {
5
public:
6
    int helper(int l,int r)
7
    {
8
        //cout<<l<<r;
9
        if(l>r) {return -1;}
10
        int mid = l+(r-l)/2;
11
        if(isBadVersion(mid) && (!isBadVersion(mid-1) || mid==0) ) {cout<<"sfds";return mid;}
12
​
13
        if(!isBadVersion(mid)) return helper(mid+1,r);
14
        else return helper(l,mid-1);
15
        
16
        
17
    }    
18
    int firstBadVersion(int n) {
19
        return helper(1,n);
20
        
21
        
22
    }
23
};
  Custom Testcase( Contribute  )
Submission Result: Accepted 
Share your acceptance!