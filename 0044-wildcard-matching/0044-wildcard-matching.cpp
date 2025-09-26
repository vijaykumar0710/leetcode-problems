class Solution {
public:
int t[2001][2001];
int m,n;
int f(int i,int j,string &s,string &p){
if(i<0 && j<0) return true;
if(i>=0 && j<0) return false;
if(i<0 && j>=0){
    for(int k=0;k<=j;k++){ 
        if(p[k]!='*') return false;
    }
    return true;
   }
   if(t[i][j]!=-1) return t[i][j];
   bool res=false;
   if(s[i]==p[j] || p[j]=='?') res|=f(i-1,j-1,s,p);
   if(p[j]=='*') res|=(f(i-1,j,s,p)||f(i,j-1,s,p));
   return t[i][j]=res;
}
    bool isMatch(string s, string p) {
        m=s.size(),n=p.size();
        memset(t,-1,sizeof(t));
        return f(m-1,n-1,s,p);
    }
};