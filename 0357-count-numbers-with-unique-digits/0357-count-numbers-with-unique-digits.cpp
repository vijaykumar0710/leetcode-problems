class Solution {
public:
int t[11][2][2][2][10000];
int f(string &s,int idx,bool tight,bool repetion,bool lz,int mask){
    if(idx==s.size()){
      if(repetion && !lz) return 1;
      return 0;
    }
    if(t[idx][tight][repetion][lz][mask]!=-1) return t[idx][tight][repetion][lz][mask];
    int ub=tight?s[idx]-'0':9;
    int ans=0;
    for(int digit=0;digit<=ub;digit++){
        int new_mask=mask;
        if(!(lz&&(digit==0))) new_mask=(mask|(1<<digit));
        ans+=f(s,idx+1,(tight&&(digit==ub)),(repetion||(mask&(1<<digit))),(lz&&(digit==0)),new_mask);
    }
    return t[idx][tight][repetion][lz][mask]=ans;
}
    int countNumbersWithUniqueDigits(int n) {
        int num=0;
        if(n==1) num=9;
        if(n==2) num=99;
        if(n==3) num=999;
        if(n==4) num=9999;
        if(n==5) num=99999;
        if(n==6) num=999999;
        if(n==7) num=9999999;
        if(n==8) num=99999999; 
        string s=to_string(num);
        memset(t,-1,sizeof(t));
        return num-f(s,0,true,false,true,0)+1;
    }
};