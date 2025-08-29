class Solution {
public:
int t[100001][27];
int f(int i,int prev_char,string &s,int k,int n){
    if(i>=n) return 0;
    if(t[i][prev_char+1]!=-1) return t[i][prev_char+1];
    int len1=0,len2=0;
    len1+=f(i+1,prev_char,s,k,n);
    int curr_char=s[i]-'a';
    if(prev_char==-1 || abs(curr_char-prev_char)<=k){
        len2+=1+f(i+1,curr_char,s,k,n);
    }
    return t[i][prev_char+1]=max(len1,len2);
}
    int longestIdealString(string s, int k) {
        int n=s.size();
        memset(t,-1,sizeof(t));
       return f(0,-1,s,k,n);
    }
};