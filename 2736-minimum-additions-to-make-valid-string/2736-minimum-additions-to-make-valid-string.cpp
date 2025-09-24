class Solution {
public:
int n;
int t[51][4];
int f(int i,int expected,string &word){
   if(i>=n) return (expected==0?0:(expected==1?2:1));
   char need=(expected==0?'a':(expected==1?'b':'c'));
   if(word[i]==need) return t[i][expected]=f(i+1,(expected+1)%3,word);
   else return t[i][expected]=1+f(i,(expected+1)%3,word);
}
    int addMinimum(string word) {
        n=word.size();
        memset(t,-1,sizeof(t));
        return f(0,0,word);
    }
};