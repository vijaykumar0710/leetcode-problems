class Solution {
public:
int n;
vector<int>t;
int f(int i,vector<int>&arr,int d){
if(i>=n) return 0;
if(t[i]!=-1) return t[i];
int jump=1;
for(int x=1;x<=d;x++){
    if(i+x<n){ 
        if(arr[i+x]>=arr[i]) break;
        jump=max(jump,1+f(i+x,arr,d));
    }
   }
   for(int x=1;x<=d;x++){
    if(i-x>=0){ 
        if(arr[i-x]>=arr[i]) break;
        jump=max(jump,1+f(i-x,arr,d));
    }
   }
   return t[i]=jump;
}
    int maxJumps(vector<int>& arr, int d) {
        n=arr.size();
        t.assign(n,-1);
        int res=0;
        for(int i=0;i<n;i++){
           res=max(res,f(i,arr,d));
        }
        return res;
    }
};