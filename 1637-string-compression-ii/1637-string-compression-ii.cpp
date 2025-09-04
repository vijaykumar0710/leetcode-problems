int t[101][101][27][101];
class Solution {
public:
int n;
int f(int i,string &s,int k,int prev,int freq){
if(k<0) return INT_MAX;
if(i>=n) return 0;
if(t[i][k][prev][freq]!=-1) return t[i][k][prev][freq];
int delete_i=f(i+1,s,k-1,prev,freq);
int keep_i=INT_MAX;
if((s[i]-'a')==prev){
    int extra_len=0;
    if(freq==1 || freq==9 || freq==99) extra_len=1;
    keep_i=extra_len+f(i+1,s,k,prev,freq+1);
   }else{
    keep_i=1+f(i+1,s,k,s[i]-'a',1);
   }
   return t[i][k][prev][freq]=min(delete_i,keep_i);
}
    int getLengthOfOptimalCompression(string s, int k) {
        n=s.size();
        memset(t,-1,sizeof(t));
        return f(0,s,k,26,0);
    }
};