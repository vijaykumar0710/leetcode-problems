class Solution {
public:
int n;
unordered_set<string>valid;
bool isValid(string &s){
    int cnt=0;
    for(int i=0;i<s.size();i++){
        if(isalpha(s[i])) continue;
        if(s[i]=='(') cnt++;
        else{
            if(cnt==0) return false;
            cnt--;
        }
    }
    return cnt==0;
}
void f(int idx,string &s,string &st){
    if(idx>=n){
        if(isValid(st)) valid.insert(st);
        return;
    }
    if(!isalpha(s[idx])) f(idx+1,s,st);
    st+=s[idx];
    f(idx+1,s,st);
    st.pop_back();
    return;
}
    vector<string> removeInvalidParentheses(string s) {
        n=s.size();
        if(isValid(s)) return {s};
        string st="";
        f(0,s,st);
        vector<string>res;
        int maxi=0;
        for(auto &str:valid){
            int sz=str.size();
            maxi=max(maxi,sz);
        }
        for(auto &str:valid){
            if(str.size()==maxi) res.push_back(str);
        }
        return res;
    }
};