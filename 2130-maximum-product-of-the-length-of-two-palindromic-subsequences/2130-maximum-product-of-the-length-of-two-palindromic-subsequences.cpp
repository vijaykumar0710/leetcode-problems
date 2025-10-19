class Solution {
public:
int n,res=0;
bool isPalin(string &s){
    int n1=s.size();
    int i=0,j=n1-1;
    while(i<=j){
       if(s[i]!=s[j]) return false;
       i++,j--;
    }
    return true;
}
 void f(int pos,string &s,string &s1,string &s2){
  if(isPalin(s1)&&isPalin(s2)){
    int len=s1.size()*s2.size();
    res=max(res,len);
  }
    for(int i=pos;i<n;i++){
        s1+=s[i]; 
        f(i+1,s,s1,s2);
        s1.pop_back();
        s2+=s[i];
        f(i+1,s,s1,s2);
        s2.pop_back();
    }
    return;
 }
    int maxProduct(string s) {
     n=s.size();
     string s1,s2;
     f(0,s,s1,s2);
     return res;
    }
};