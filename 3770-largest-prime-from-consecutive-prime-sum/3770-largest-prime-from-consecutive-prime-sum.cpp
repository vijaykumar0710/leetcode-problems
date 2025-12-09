bool isBuilt=false;
    static const int N=500005;
    vector<int>prime_num;
    vector<bool>prime;
    vector<long long>prefix;
    void sieve(){ 
    prime.assign(N+1,true);
    prime[0]=prime[1]=false;
    for(int i=2;i*i<=N;i++){
        if(prime[i]){
            for(int j=i*i;j<=N;j+=i) prime[j]=false;
        }
      }
    for(int i=2;i<=N;i++){
        if(prime[i]) prime_num.push_back(i);
       }
        prefix.resize(prime_num.size());
        prefix[0]=prime_num[0];
        for(int i=1;i<prime_num.size();i++){
           prefix[i]=prefix[i-1]+prime_num[i];
        }
    }
class Solution {
public:

    int largestPrime(int n) {
        if(!isBuilt){ 
          sieve();
            isBuilt=true;
        }
        long long res=LLONG_MIN;
       for(int i=0;i<prefix.size();i++){
           if(prefix[i]<=n && prime[prefix[i]]) res=max(res,prefix[i]);
           if(prefix[i]>n) break;
       }
      return res==LLONG_MIN?0:res;
    }
};