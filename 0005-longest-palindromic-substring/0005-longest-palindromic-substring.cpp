class Solution {
public:
int start=-1,max_len=0;
void expand(string & s,int l,int r){
    int n=s.size();
    while(l>=0 && r<n && s[l]==s[r]){
        if(r-l+1>max_len){ 
        max_len=r-l+1;
        start=l;
        }
        l--;
        r++;
    }
}
    string longestPalindrome(string s) {
        int n=s.size();
        if(n==0) return "";
        for(int i=0;i<n;i++){
         expand(s,i,i);// odd length string
         expand(s,i,i+1); // even length string
        }
        return s.substr(start,max_len);
    }
};