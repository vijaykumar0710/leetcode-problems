class Solution {
public:
vector<vector<double>>t;
double f(int A,int B){
   if(A<=0 && B<=0) return 0.5;
   if(A<=0) return 1.0;
   if(B<=0) return 0.0;
   if(t[A][B]!=-1.0) return t[A][B];
    double p1=f(A-100,B);
    double p2=f(A-75,B-25);
    double p3=f(A-50,B-50);
    double p4=f(A-25,B-75);
    return t[A][B]=0.25*(p1+p2+p3+p4);
}
    double soupServings(int n) {
        if(n>=5000) return 1;
        t.resize(n+1,vector<double>(n+1,-1.0));
        return f(n,n);
    }
};