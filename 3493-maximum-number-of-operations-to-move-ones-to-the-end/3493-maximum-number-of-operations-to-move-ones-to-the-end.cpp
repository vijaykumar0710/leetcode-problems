class Solution {
public:
    int maxOperations(string s) {
     int n=s.size();
     int cnt=0,res=0;
     int i=0;
     while(i<n){
        if(s[i]=='1') cnt++,i++;
        if(s[i]=='0'){
            res+=cnt;
            while(s[i]=='0') i++;
        }
      }  
      return res; 
    }
};