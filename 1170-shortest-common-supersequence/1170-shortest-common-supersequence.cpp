class Solution {
public:
// length of scs=m+n-lcs(s1,s2)
    string shortestCommonSupersequence(string str1, string str2) {
        int m=str1.size(),n=str2.size();
        // lcs code
      vector<vector<int>>t(m+1,vector<int>(n+1));
       for(int i=0;i<m+1;i++)
          t[i][0]=0;
        for(int j=0;j<n+1;j++)
          t[0][j]=0;
          for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
             if(str1[i-1]==str2[j-1]){
                t[i][j]=1+t[i-1][j-1];
             }
              else  t[i][j]=max(t[i-1][j],t[i][j-1]);
             }
          }
     string scs="";
     int i=m,j=n;
     while(i>0 && j>0){
        if(str1[i-1]==str2[j-1]){
            scs+=str1[i-1];
            i--,j--;
        }else{
            if(t[i-1][j]>t[i][j-1]){
                scs+=str1[i-1];
                i--;
            }else{
                scs+=str2[j-1];
                j--;
            }
        }
     }
     while(i>0){
        scs+=str1[i-1];
        i--;
     }
     while(j>0){
        scs+=str2[j-1];
        j--;
     }
     reverse(scs.begin(),scs.end());
     return scs;
    }
};