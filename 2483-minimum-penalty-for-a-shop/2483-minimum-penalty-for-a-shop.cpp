class Solution {
public:
    int bestClosingTime(string c) {
        int n=c.size();
        vector<int>p(n,0),s(n,0);
        if(c[0]=='N') p[0]=1;
        if(c[n-1]=='Y') s[n-1]=1;
        for(int i=1;i<n;i++){
          if(c[i]=='N') p[i]=p[i-1]+1;
          else p[i]=p[i-1];
        }
        for(int i=n-2;i>=0;i--){
          if(c[i]=='Y') s[i]=s[i+1]+1;
          else s[i]=s[i+1];
        }
        int res;
        if(p[n-1]>=s[0]) res=0;
        else res=n;
        int temp=s[0];
        for(int i=0;i<n-1;i++){
            if(s[i+1]+p[i]<temp){
                temp=s[i+1]+p[i];
                res=i+1;
            }
        }
        if(temp>p[n-1]) res=n;
        return res;
    }
};