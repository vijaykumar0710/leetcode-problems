const int M=1e9+7;
long long fact(int x){
    if(x==1) return 1;
    long long res=1;
    res=1LL*x*fact(x-1)%M;
    return res;
}
class Solution {
public:
    int countPermutations(vector<int>& cmp) {
      int n=cmp.size();
      for(int i=1;i<n;i++) if(cmp[i]<=cmp[0]) return 0;
      return fact(n-1);
    }
};