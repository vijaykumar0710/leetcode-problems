class Solution {
public:
int n;
int res=INT_MAX;
void f(int idx,vector<int>& cookies, int k,vector<int>&temp){
  if(idx>=n){
     int maxi=*max_element(temp.begin(),temp.end());
      res=min(res,maxi);
      return;
  }
for(int i=0;i<k;i++){
temp[i]+=cookies[idx];
f(idx+1,cookies,k,temp);
temp[i]-=cookies[idx];
  }
}
    int distributeCookies(vector<int>& cookies, int k) {
        n=cookies.size();
        vector<int>temp(k,0);
        f(0,cookies,k,temp);
        return res;
    }
};