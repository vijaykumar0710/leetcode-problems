class Solution {
public:
int n;
bool f(int i,string &s,int cnt){
  if(cnt<0) return false;
  if(i>=n) return cnt==0;
  bool ans=false;
  if(s[i]=='(')  ans|=f(i+1,s,cnt+1);
  else if(s[i]==')') ans|=f(i+1,s,cnt-1);
  else{
    ans|=f(i+1,s,cnt);
    ans|=f(i+1,s,cnt-1);
    ans|=f(i+1,s,cnt+1);
  }
  return ans;
}
    bool checkValidString(string s) {
        n=s.size();
        return f(0,s,0);
    }
};