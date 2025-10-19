class Solution {
public:
int n;
unordered_set<string>st;
string f(string s,string &res,int a,int b){
if(st.count(s)) return res;
st.insert(s);
res=min(res,s);
string rot=s;
rotate(rot.begin(),rot.end()-b,rot.end());
f(rot,res,a,b);
string add=s;
for(int i=1;i<n;i+=2){
    int x=(add[i]-'0'+a)%10;
    add[i]='0'+x;
  }
  f(add,res,a,b);
  return res;
}
    string findLexSmallestString(string s, int a, int b) {
     n=s.size();
     string res=s;
     return f(s,res,a,b);
    }
};