class DisjointSet{
    public:
    vector<int>size,parent;

    DisjointSet(int n){
        size.resize(n,1);
        parent.resize(n);
        for(int i=0;i<n;i++) parent[i]=i;
    }

    int findUPar(int u){
        if(u==parent[u]) return u;
        return parent[u]=findUPar(parent[u]);
    }

    void unionBySize(int u, int v){
        int uParU = findUPar(u);
        int uParV = findUPar(v);        

        if (uParU == uParV) return;

        if(size[uParU] < size[uParV]){
            parent[uParU]=uParV;
            size[uParV]+=size[uParU];
        }
        else{
            parent[uParV]=uParU;
            size[uParU]+=size[uParV];
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {

        DisjointSet ds(n);
        int edges = connections.size();

        int extraEdges=0;

        for(auto connection:connections){
            int upar_u = ds.findUPar(connection[0]);
            int upar_v = ds.findUPar(connection[1]);
            if(upar_u==upar_v){
                //already connected
                extraEdges++;
            }
            else{
                ds.unionBySize(connection[0],connection[1]);
            }
        }

        //find components
        int components=0;
        for(int i=0;i<n;i++){
            if(ds.parent[i]==i) components++;
        }


        if(extraEdges<components-1) return -1;
        return components-1;



    }
};  