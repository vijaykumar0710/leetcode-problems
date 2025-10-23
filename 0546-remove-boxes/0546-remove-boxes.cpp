class Solution {
public:
int t[101][101][101];
int f(vector<int>&boxes,int l,int r,int k){
    if(l>r) return 0;
    if(t[l][r][k]!=-1) return t[l][r][k];
    int origL=l,origK=k;
    while(l+1<=r && boxes[l]==boxes[l+1]){
        l++,k++;
    }
    int res=(k+1)*(k+1)+f(boxes,l+1,r,0);
    for(int m=l+1;m<=r;m++){
        if(boxes[l]==boxes[m]){
            res=max(res,f(boxes,l+1,m-1,0)+f(boxes,m,r,k+1));
        }
    }
    return t[origL][r][origK]=res;
}
    int removeBoxes(vector<int>& boxes) {
        memset(t,-1,sizeof(t));
        return f(boxes,0,boxes.size()-1,0);
    }
};