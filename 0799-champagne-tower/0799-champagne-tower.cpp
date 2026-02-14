class Solution {
public:
double t[101][101];
double solve(int poured, int query_row, int query_col){
       if(query_row<0.0 || query_col<0.0 || query_row<query_col) return 0.0;
       if(query_row==0 && query_col==0) return poured;
       if(t[query_row][query_col]!=-1) return t[query_row][query_col];
       double left=max(0.0,(solve(poured,query_row-1,query_col-1)-1)/2.0);
       double right=max(0.0,(solve(poured,query_row-1,query_col)-1)/2.0);
       return t[query_row][query_col]=(double)left+right;
}
    double champagneTower(int poured, int query_row, int query_col) {
        for(int i=0;i<101;i++){
            for(int j=0;j<101;j++){
                t[i][j]=-1;
            }
        }
       return min(1.0,solve(poured,query_row,query_col));
    }
};