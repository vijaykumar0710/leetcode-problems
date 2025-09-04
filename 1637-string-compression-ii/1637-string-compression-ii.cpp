class Solution {
public:
int n;
int t[101][101];
int f(int i,string &s,int k){
    if(k<0) return 1001;
    if(i>=n || n-i<=k) return 0;
    if(t[i][k]!=-1) return t[i][k];
    int delete_i=f(i+1,s,k-1);
    int keep_i=INT_MAX;
    int deleted=0;
    int extra=0,freq=0;
    for(int j=i;j<n && deleted<=k;j++){
        if(s[i]==s[j]){
          freq++;
        if(freq==2 || freq==10 || freq==100) extra++;
        }else{
            deleted++;
        }
      keep_i=min(keep_i,1+extra+f(j+1,s,k-deleted));
    }
    return t[i][k]=min(keep_i,delete_i);
}
    int getLengthOfOptimalCompression(string s, int k) {
        n=s.size();
        memset(t,-1,sizeof(t));
        return f(0,s,k);
    }
};