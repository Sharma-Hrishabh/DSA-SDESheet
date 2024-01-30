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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        map<string,int>mp;
        int n = accounts.size();
        
        DisjointSet ds(n);

        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                if(mp.find(accounts[i][j])==mp.end()){
                    //if not present in map
                    mp.insert({accounts[i][j],i});
                }
                else{
                    ds.unionBySize(i,mp[accounts[i][j]]);
                }
            }
        }  

        vector<vector<string>>mergedEmails(n);

        for(auto it:mp){
            string email = it.first;
            int parent = ds.findUPar(it.second);
            mergedEmails[parent].push_back(email);
        }

        vector<vector<string>>ans;

        for(int i=0;i<n;i++){
            if(mergedEmails[i].size()==0) continue;
            sort(mergedEmails[i].begin(),mergedEmails[i].end());

            vector<string>temp;
            temp.push_back(accounts[i][0]);
            for(auto it:mergedEmails[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }

        return ans;

    }
};