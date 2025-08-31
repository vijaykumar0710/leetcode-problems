const int M=1e9+7;
class Solution {
public:
int n;
int t[101][201];
int f(vector<int>&locations,int start,int finish,int fuel){
  if(fuel<0) return 0;
  if(t[start][fuel]!=-1) return t[start][fuel];
  int cnt=0;
  if(start==finish) cnt++;
  for(int i=0;i<n;i++){
    int amount=abs(locations[i]-locations[start]);
    if(fuel-amount>=0 && i!=start){
        cnt=(cnt+f(locations,i,finish,fuel-amount))%M;
    }
  }
  return t[start][fuel]=cnt%M;
}
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        n=locations.size();
        memset(t,-1,sizeof(t));
        return f(locations,start,finish,fuel);
    }
};