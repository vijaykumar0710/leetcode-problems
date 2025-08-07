class Solution {
public:
int n;
int t[1001][1001];
int child1(vector<vector<int>>& fruits){
   int sum=0;
   for(int i=0;i<n;i++) sum+=fruits[i][i];
   return sum;
}
int child2(int i,int j,vector<vector<int>>& fruits){
  if(i>=n || j<0 || j>=n || i>=j) return 0;
  if(i==n-1 && j==n-1) return 0;
  if(t[i][j]!=-1) return t[i][j];
  int x1=fruits[i][j]+child2(i+1,j-1,fruits);
  int x2=fruits[i][j]+child2(i+1,j,fruits);
  int x3=fruits[i][j]+child2(i+1,j+1,fruits);

  return t[i][j]=max({x1,x2,x3});
}
int child3(int i,int j,vector<vector<int>>& fruits){
  if(i>=n || i<0 || j>=n || i<=j) return 0;
  if(i==n-1 && j==n-1) return 0;
  if(t[i][j]!=-1) return t[i][j];
  int x1=fruits[i][j]+child3(i-1,j+1,fruits);
  int x2=fruits[i][j]+child3(i,j+1,fruits);
  int x3=fruits[i][j]+child3(i+1,j+1,fruits);

  return t[i][j]=max({x1,x2,x3});
}
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        n=fruits.size();
        int c1=child1(fruits);
        memset(t,-1,sizeof(t));
        int c2=child2(0,n-1,fruits);
         memset(t,-1,sizeof(t));
        int c3=child3(n-1,0,fruits);
        return c1+c2+c3;
    }
};