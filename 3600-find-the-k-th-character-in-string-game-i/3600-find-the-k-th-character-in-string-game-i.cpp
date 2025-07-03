class Solution {
public:
unordered_map<int,string>t;
string solve(int pow){
    if(pow==1) return "a";
    if(t.find(pow)!=t.end()) return t[pow];
    string temp=solve(pow/2);
    string res;
    res=temp;
    for(auto ch:temp){
        res+='a'+(ch-'a'+1)%26;
    }
    return t[pow]=res;
}
    char kthCharacter(int k) {
       int pow=512;
        string res=solve(pow);
        return res[k-1];
    }
};