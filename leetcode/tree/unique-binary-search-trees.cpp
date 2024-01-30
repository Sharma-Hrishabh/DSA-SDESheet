class Solution {
public:
    /*
    G[i] is the function that gives no of BSTs for a length sequence n
    F[i,n] is the function which can derive G[n] with i as root node.
    F[i,n] = G[i-1] * G[n-i];
    G[n] = F(1,n)+F(2,n)+......F(n.n);
    G[n] = G(0)*G(n-1) + G(1)*G(n-2) + ..........G(n-1)*G(0) 
    */
    
    int numTrees(int n) {
     
        vector<int>G(n+1,0);
        
        G[0]=1;
        G[1]=1;
        
        for(int i=2;i<=n;i++){
            for(int j=1;j<=i;j++){
                G[i] += G[j-1]*G[i-j];
            }
        }
        
        
        return G[n];
    }
    
    
    
  //  TLE
//     int numTrees(int n) {
//         return trees(1, n);
//     }

//     int trees(int lo, int hi) {
//         if (lo >= hi) return 1;
//         int total = 0;
//         for (int i = lo; i <= hi; i++)
//             total += trees(lo, i - 1) * trees(i + 1, hi);
//         return total;
//     }
};


