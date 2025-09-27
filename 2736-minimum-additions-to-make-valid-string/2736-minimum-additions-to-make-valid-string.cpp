class Solution {
public:
int n;
int t[51][4];
int f(int i,int expected,string &s){
   if(i>=n){
    if(expected==0) return 0;
    if(expected==1) return 2;
    if(expected==2) return 1;
   }
   if(t[i][expected]!=-1) return t[i][expected];
   int cnt=0;
   char expect_char=expected+'a';
   if(s[i]==expect_char) cnt+=f(i+1,(expected+1)%3,s);
   else cnt+=1+f(i,(expected+1)%3,s);
   return t[i][expected]=cnt;
}
    int addMinimum(string word) {
        n=word.size();
        memset(t,-1,sizeof(t));
        return f(0,0,word);
    }
};