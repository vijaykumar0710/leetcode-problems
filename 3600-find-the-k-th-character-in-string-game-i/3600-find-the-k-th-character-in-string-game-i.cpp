class Solution {
public:
unordered_map<int,string>t;
string solve(int pow,string &res){
    if(pow==1) return "a";
    if(t.find(pow)!=t.end()) return t[pow];
    string temp=solve(pow/2,res);
    res=temp;
    for(auto ch:temp){
        res+='a'+(ch-'a'+1)%26;
    }
    return t[pow]=res;
}
    char kthCharacter(int k) {
       int pow=512;
        string res;
        solve(pow,res);
        return res[k-1];
    }
};