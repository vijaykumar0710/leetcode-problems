class Solution {
public:
    int minFlips(string s) {
        int n=s.size();
        int res=INT_MAX;
        s=s+s;
        int m=s.size();
        string s1,s2;
        s1='0',s2='1';
        for(int i=1;i<m;i++){
            if(s1[i-1]=='0') s1+='1';
            else s1+='0';
        }
        for(int i=1;i<m;i++){
            if(s2[i-1]=='0') s2+='1';
            else s2+='0';
        }
        int f1=0;
        for(int i=0;i<m;i++){
          if(s1[i]!=s[i]) f1++;
          if(i>=n){
            if(s[i-n]!=s1[i-n]) f1--;
            res=min(res,f1);
          }
        }
        f1=0;
        for(int i=0;i<m;i++){
          if(s2[i]!=s[i]) f1++;
          if(i>=n){
            if(s[i-n]!=s2[i-n]) f1--;
            res=min(res,f1);
          }
        }
        return res;
    }
};