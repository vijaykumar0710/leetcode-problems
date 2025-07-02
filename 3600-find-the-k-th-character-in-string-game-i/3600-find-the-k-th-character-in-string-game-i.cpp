class Solution {
public:
string solve(int pow,string &res){
    if(pow==1) return "a";
    string temp=solve(pow/2,res);
    res=temp;
    for(auto ch:temp){
        res+='a'+(ch-'a'+1)%26;
    }
    return res;
}
    char kthCharacter(int k) {
       int pow=512;
        string res;
        solve(pow,res);
        return res[k-1];
    }
};