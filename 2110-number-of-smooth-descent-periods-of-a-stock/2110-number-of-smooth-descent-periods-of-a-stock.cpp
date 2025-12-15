class Solution {
public:
    long long getDescentPeriods(vector<int>& p) {
        int n=p.size();
        long long res=0,x=1;
        for(int i=1;i<n;i++){
           if(p[i-1]-p[i]==1) x++;
           else{
            res=(long long)res+(1LL*x*(x+1))/2;
              x=1;
           }
        }
        res=(long long)res+(1LL*x*(x+1))/2;
        return res;
    }
};