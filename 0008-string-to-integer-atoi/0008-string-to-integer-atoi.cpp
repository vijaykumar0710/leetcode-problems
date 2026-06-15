class Solution {
public:
    int myAtoi(string s) {
        int n=s.size();
        string st="";
        bool neg=false;
        bool pos=false;
        int i=0;
        while(i<n && s[i]==' ')i++;
        if(i<n && s[i]=='+'){
            if(pos) return 0;
            pos=true;
            i++;
        };
        if(i<n && s[i]=='-'){
            if(pos) return 0;
            if(neg) return 0;
            neg=true;
            i++;
        }
        for(;i<n;i++){
            if(!isdigit(s[i])) break;
            if(isdigit(s[i])) st+=s[i];
        }
          int j=0;
          while(j<st.size() && st[j]=='0') j++;
          st=st.substr(j);
          if(st.empty()) return 0;
          double long num=0;
          for(char ch : st) {
        num =1LL*num * 10 + (ch - '0');
        }
          if(neg){
            num=-1*num;
            if(num<-1*pow(2,31)){
            num=-1*pow(2,31);
            }
            return (long long)num;
          }
          if(num>pow(2,31)-1) return (long long)pow(2,31)-1;
          return num;
    }
};