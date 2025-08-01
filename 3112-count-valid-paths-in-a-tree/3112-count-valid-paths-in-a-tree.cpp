class Solution {
public:
vector<int>parent;
//size of connected non-prime components
vector<long long>component_size;
int find(int x){
    if(x==parent[x]) return x;
    return parent[x]=find(parent[x]);
}
void Union(int x,int y){// Union by size compression
    int x_par=find(x);
    int y_par=find(y);
    if(x_par==y_par) return;
    if(component_size[x_par]>component_size[y_par]){
     parent[y_par]=x_par;
     component_size[x_par]+=component_size[y_par];
    }else if(component_size[x_par]<component_size[y_par]){
     parent[x_par]=y_par;
     component_size[y_par]+=component_size[x_par];
    }else{
     parent[y_par]=x_par;
     component_size[x_par]+=component_size[y_par];
    }
}
    long long countPaths(int n, vector<vector<int>>& edges) {
        // sieve
        vector<bool>isPrime(n+1,true);
        isPrime[0]=isPrime[1]=false;
        for(int i=2;i*i<=n;i++){
            if(isPrime[i]){
                for(int j=2;i*j<=n;j++) 
                    isPrime[i*j]=false;
                }
            }

        // dsu initialisation
         parent.resize(n+1);
         component_size.resize(n+1);
         for(int i=1;i<=n;i++){
            parent[i]=i;
            // only non-prime nodes contribute to component_size initially
            component_size[i]=isPrime[i]?0:1;
         }
        
        // adjacency list and make Union of non-prime nodes
          vector<vector<int>>adj(n+1);
         for(auto &e:edges){
          int u=e[0];
          int v=e[1];
          adj[u].push_back(v);
          adj[v].push_back(u);
          if(!isPrime[u] && !isPrime[v]) // if both nodes are non-prime
             Union(u,v);
        }

        // Iterate through prime node
       long long total_valid_nodes=0;
       for(int i=1;i<=n;i++){
        if(!isPrime[i]) continue; // only process prime nodes
        long long sum_of_branch_sizes=0;
        vector<long long> branch_sizes;
        for(auto &neigh:adj[i]){
        // if neigh is non-prime then find size of non-prime components the neigh belongs to
        long long size=component_size[find(neigh)];
         branch_sizes.push_back(size);
         sum_of_branch_sizes+=size;
        }
       // path type 1.(NP--P)
       // Each non-prime node in branch sizes forms a valid path with prime nodes
       total_valid_nodes+=sum_of_branch_sizes;
       // path type 2.(NP--P---NP)
       // formula:- (Sum of sizes)^2-(Sum of Squares of sizes)/2
       long long sum_of_squares=0;
       for(auto sz:branch_sizes) sum_of_squares+=sz*sz;
       total_valid_nodes+=(sum_of_branch_sizes*sum_of_branch_sizes-sum_of_squares)/2;
       }
       return total_valid_nodes;
    }
};