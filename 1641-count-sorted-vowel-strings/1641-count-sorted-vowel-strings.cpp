class Solution {
public:
int t[51][6];
int f(int n,int last){
    if(n==0) return 1;
    if(t[n][last]!=-1) return t[n][last];
    int res=0;
    for(int i=0;i<5;i++){
       if(last<=i)
        res+=f(n-1,i);
    }
    return t[n][last]=res;
}
    int countVowelStrings(int n) {
        memset(t,-1,sizeof(t));
        return f(n,0);
    }
};