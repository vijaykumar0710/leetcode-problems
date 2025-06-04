class Solution {
public:
bool isPalindrome(int l,int r,string &s){
    while(l<=r){
        if(s[l]!=s[r]) return false;
        l++,r--;
    }
    return true;
}
    bool checkPartitioning(string s) {
        int n=s.size();
        for(int i=0;i<n-1;i++){
            if(isPalindrome(0,i,s)){
                for(int j=i+1;j<n-1;j++){
                  if(isPalindrome(i+1,j,s) && isPalindrome(j+1,n-1,s))
                      return true;
                }
            }
        }
        return false;
    }
};