class Solution {
public:
const int M=1e9+7;
   vector<vector<long long>>multiply(vector<vector<long long>>&A,vector<vector<long long>>&B){
       int n=A.size();
       vector<vector<long long>>C(n,vector<long long>(n,0));
       for (int i = 0; i < n; i++) {
            for (int k = 0; k < n; k++) {
                if (A[i][k] == 0) continue;
                for (int j = 0; j < n; j++) {
                    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % M;
                }
            }
        }
       return C;
   }
   vector<long long>multiplyMatVec(vector<vector<long long>>&A,vector<long long>&B){
    int n=A.size();
    vector<long long>res(n);
    for(int i=0;i<n;i++){
      long long sum=0;
      for(int j=0;j<n;j++){
        sum=(sum+A[i][j]*B[j])%M;
      }
      res[i]=sum;
    }
    return res;
   }
    int zigZagArrays(int n, int l, int r) {
        if(n==1) return r-l+1;
        int S=2*(r+1);
        vector<long long>state(S,0);
        for(int v=l;v<=r;v++){
            state[v]=v-l;
            state[r+1+v]=r-v;
        }
        if(n==2){
            long long ans=0;
            for(int i=0;i<S;i++){
                ans=(ans+state[i])%M;
            }
            return ans;
        }
        vector<vector<long long>>T(S,vector<long long>(S,0));
        for(int v=l;v<=r;v++){
            for(int x=l;x<v;x++){
                 T[v][r+1+x]=1;
            }
        }
        for(int v=l;v<=r;v++){
            for(int x=v+1;x<=r;x++){
                 T[r+1+v][x]=1;
            }
        }
        long long power=n-2;
        while(power>0){
            if(power&1){
               state=multiplyMatVec(T,state);  // s(3)=T*s(2); 
            }
            T=multiply(T,T);
            power/=2;
        }
        long long ans=0;
        for(int i=0;i<S;i++){
            ans=(ans+state[i])%M;
        }
        return ans;
    }
};