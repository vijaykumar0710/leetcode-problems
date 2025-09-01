const int M=1e9+7;
class Solution {
public:
int n;
int t[10001][6][11][11];
int f(int i,int len,int first,int second,string &s){
   if(len==5) return 1;
   if(i>=n) return 0;
   if(t[i][len][first][second]!=-1) return t[i][len][first][second];
   int cnt=0;
   cnt=(cnt+f(i+1,len,first,second,s))%M;
   if(len==0) cnt=(cnt+f(i+1,len+1,s[i]-'0',second,s))%M;
   else if(len==1) cnt=(cnt+f(i+1,len+1,first,s[i]-'0',s))%M;
   else if(len==2) cnt=(cnt+f(i+1,len+1,first,second,s))%M;
   else if(len==3){
      if(s[i]-'0'==second) cnt=(cnt+f(i+1,len+1,first,second,s))%M;
   }
   else if(len==4){
      if(s[i]-'0'==first) cnt=(cnt+f(i+1,len+1,first,second,s))%M;
   }
   return t[i][len][first][second]=cnt%M;
}
    int countPalindromes(string s) {
        n=s.size();
        memset(t,-1,sizeof(t));
        return f(0,0,10,10,s);
    }
};