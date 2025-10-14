class Solution {
public:
int t[16];
int n;
 bool isValid(string &s, int st, int end) {
        if (s[st] == '0') return false;
        long long num = 0;
        for (int i = st; i <= end; i++) {
            num = num * 2 + (s[i] - '0');
        }
        if (num <= 0) return false;
        while (num % 5 == 0) num /= 5;
        return num == 1;
    }
int f(string &s,int i){
if(i>=n) return 0;
if(t[i]!=-1) return t[i];
int ans=n+1;
  for(int k=i;k<n;k++){
    int temp=INT_MAX;
    if(isValid(s,i,k)){
        temp=1+f(s,k+1);
    }
    ans=min(ans,temp);
  }
  return t[i]=ans;
}
    int minimumBeautifulSubstrings(string s) {
        n=s.size();
        memset(t,-1,sizeof(t));
        int res=f(s,0);
        if(res==n+1) return -1;
        return res;
    }
};