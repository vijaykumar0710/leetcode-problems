class Solution {
public:
    int minimumTime(string s) {
        int n=s.size();
        vector<int>prefix(n,0),suffix(n,0);
        if(s[0]=='1') prefix[0]=1;
        if(s[n-1]=='1') suffix[n-1]=1;
        for(int i=1;i<n;i++){
          if(s[i]=='0') prefix[i]=prefix[i-1];
          else prefix[i]=min(i+1,prefix[i-1]+2);
        }
        for(int j=n-2;j>=0;j--){
            if(s[j]=='0') suffix[j]=suffix[j+1];
            else suffix[j]=min(n-j,suffix[j+1]+2);
        }
        int res=min(prefix[n-1],suffix[0]);
        for(int k=0;k<n-1;k++){
            res=min(res,prefix[k]+suffix[k+1]);
        }
        return res;
    }
};