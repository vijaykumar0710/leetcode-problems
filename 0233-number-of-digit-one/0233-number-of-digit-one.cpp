class Solution {
public:
int t[11][2][10];
int f(string &s,int idx,bool tight,int cnt){
    if(idx==s.size()) return cnt;
    if(t[idx][tight][cnt]!=-1) return t[idx][tight][cnt];
    int ub=tight?s[idx]-'0':9;
    int ans=0;
    for(int digit=0;digit<=ub;digit++){
        int update_cnt=cnt+(digit==1?1:0);
       ans+=f(s,idx+1,(tight&&digit==ub),update_cnt);
    }
    return t[idx][tight][cnt]=ans;
}
    int countDigitOne(int n) {
        string s=to_string(n);
        memset(t,-1,sizeof(t));
        return f(s,0,1,0);
    }
};