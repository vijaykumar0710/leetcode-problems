class Solution {
public:
    long long maximumSubsequenceCount(string text, string pattern) {
        int m=text.size();
        long long schar=0;
        for(auto ch:text) if(ch==pattern[1]) schar++;
    string s1=pattern[0]+text;
    long long res=INT_MIN,cnt=0;
    long long pcnt=0;
    for(int i=0;i<=m;i++){
    if(s1[i]==pattern[1]) pcnt++;
    if(s1[i]==pattern[0]) cnt+=(schar-pcnt);
      }
    res=max(res,cnt);
    s1=text+pattern[1];
    schar++;
    pcnt=0;
    cnt=0;
    for(int i=0;i<=m;i++){
    if(s1[i]==pattern[1]) pcnt++;
    if(s1[i]==pattern[0]) cnt+=(schar-pcnt);
      }
      res=max(res,cnt);
      return res;
    }
};