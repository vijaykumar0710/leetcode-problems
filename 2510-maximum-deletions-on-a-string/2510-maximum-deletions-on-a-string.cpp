class Solution {
public:
    int deleteString(string s) {
        int n=s.size();
        vector<vector<int>>lcp(n+1,vector<int>(n+1,0));
        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(s[i]==s[j]) lcp[i][j]=1+lcp[i+1][j+1];
            }
        }
        vector<int>t(n+1,0);
        for(int i=n-1;i>=0;i--){
            t[i]=1;
            for(int len=1;i+2*len<=n;len++){
              if(lcp[i][i+len]>=len)  t[i]=max(t[i],1+t[i+len]);
            }
        }
        return t[0];
    }
};