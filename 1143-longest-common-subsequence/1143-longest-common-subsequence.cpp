class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.size();
        int n=text2.size();
        vector<int>t(n+1,0);
        for(int i=1;i<=m;i++){
            vector<int>temp(n+1,0);
            for(int j=1;j<=n;j++){
                if(text1[i-1]==text2[j-1]) temp[j]=1+t[j-1];
                else temp[j]=max(temp[j-1],t[j]);
            }
            t=temp;
        }
        return t[n];
    }
};