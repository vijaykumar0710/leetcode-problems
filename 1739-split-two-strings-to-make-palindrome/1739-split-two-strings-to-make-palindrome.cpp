class Solution {
public:
bool checkPalin(string &s){
    int l=0,r=s.size()-1;
    while(l<=r){
        if(s[l]!=s[r]) return false;
        l++,r--;
    }
    return true;
}
bool solve(string &a ,string &b){
    int n=a.size();
    int i=0,j=n-1;
    while(i<=j){
      if(a[i]==b[j]) i++,j--;
      else break;
    }
    if(i>=j) return true;
    string s=b.substr(i,j-i+1);
    string s2=a.substr(i,j-i+1);
    return checkPalin(s)||checkPalin(s2);
}
    bool checkPalindromeFormation(string a, string b) {
        return solve(a,b) || solve(b,a);
    }
};