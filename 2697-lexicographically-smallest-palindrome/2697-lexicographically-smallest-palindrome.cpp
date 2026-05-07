class Solution {
public:
    string makeSmallestPalindrome(string s) {
        int n=s.size();
        int i=0,j=n-1;
        while(i<j){
            s[i]=min(s[i],s[j]),s[j]=min(s[i],s[j]);
            i++,j--;
        }
        return s;
    }
};