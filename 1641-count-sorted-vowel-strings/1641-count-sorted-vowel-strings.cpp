class Solution {
public:
int f(int n,char last,string &s){
    if(n==0) return 1;
    int res=0;
    for(int i=0;i<s.size();i++){
       if(last<=s[i])
        res+=f(n-1,s[i],s);
    }
    return res;
}
    int countVowelStrings(int n) {
        string s="aeiou";
        return f(n,'a',s);
    }
};