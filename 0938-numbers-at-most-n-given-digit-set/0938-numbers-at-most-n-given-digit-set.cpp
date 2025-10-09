class Solution {
public:
 unordered_set<int>st;
 int t[11][2][2];
int f(string &s,int idx,bool tight,bool lz){
    if(idx==s.size()){
      if(!lz) return 1;
      return 0;
    }
if(t[idx][tight][lz]!=-1) return t[idx][tight][lz];
    int ub=tight?s[idx]-'0':9;
    int res=0;
    for(int digit=0;digit<=ub;digit++){
        if(st.count(digit) || (lz && digit == 0)){
            res+=f(s,idx+1,(tight&&(ub==digit)),(lz&&(digit==0)));
        }
    }
    return t[idx][tight][lz]=res;
}
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        string s=to_string(n);
        for(auto ch:digits){
            int num=stoi(ch);
            st.insert(num);
        }
        memset(t,-1,sizeof(t));
        return f(s,0,true,true);
    }
};