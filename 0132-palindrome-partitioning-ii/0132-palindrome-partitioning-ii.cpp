class Solution {
public:
  int t[2001][2001];
  bool isPalindrome(string &s,int i,int j){
     while(i<j){
       if(s[i]!=s[j]){
        return false;
       }
       i++;
       j--;
     }
      return true;
  }
  int solve(string &s,int i,int j){
    if(t[i][j]!=-1) return t[i][j];
    if(i>=j || isPalindrome(s,i,j)) return 0;
     int mini=INT_MAX;
     for(int k=i;k<=j-1;k++){ 
        if(isPalindrome(s,i,k)){ 
        int temp=1+solve(s,k+1,j);
        mini=min(mini,temp);
         t[i][j]=mini;
        }
     }
     return t[i][j]=mini;
  }
    int minCut(string s) {
        int i=0,j=s.length()-1;
        memset(t,-1,sizeof(t));
        return solve(s,i,j);
    }
};