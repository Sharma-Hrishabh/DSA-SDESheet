
// Consider an example
// a a c e c a a a a

// Here “a a c e c a a” is the palindromic substring at the start. In “a b c b” for instance, 
// “a” is the longest palindromic substring from the beginning.

// Creating the pattern and its LPS array for the first example, we get -

// str = a a c e c a a a a # a a a a c e c a a
// lps = 0 1 0 0 0 1 2 2 2 0 1 2 2 2 3 4 5 6 7

// 7 is the length of the substring that is a palindrome from the start of the given string. 


// Since the length of the actual string is 9, adding those remaining two elements to 
// the original string will make it a palindrome, hence the answer is 9 - 7 = 2.

int Solution::solve(string A) {
    
    int j=0;
    int i=1;
    string b = A;
    reverse(b.begin(),b.end());
    string a = A + "$" + b;
    int N = a.length();
    vector<int>lps(N);
    lps[0]=0;
    while(i<N){
        if(a[j]==a[i]){
            j++;
            lps[i]=j;
            i++;
        }
        else{
            if(j!=0){
                j=lps[j-1];
            }
            else{
                lps[i]=0;
                i++;
            }
        }
    }


    return A.length()-lps[N-1];
}
