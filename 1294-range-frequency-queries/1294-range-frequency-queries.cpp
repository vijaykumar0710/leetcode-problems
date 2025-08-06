class RangeFreqQuery {
public:
int n;
vector<unordered_map<int,int>>segTree;
void buildSegTree(int i,int l,int r,vector<int>&arr){
if(l==r){
    segTree[i][arr[l]]=1;
    return;
}
int mid=l+(r-l)/2;
buildSegTree(2*i+1,l,mid,arr);
buildSegTree(2*i+2,mid+1,r,arr);
for(auto &[val,cnt]:segTree[2*i+1]) segTree[i][val]+=cnt; 
for(auto &[val,cnt]:segTree[2*i+2]) segTree[i][val]+=cnt;
}

int solve(int i,int l,int r,int start,int end,int val){
  if(r<start || l>end) return 0;
  if(r<=end && l>=start) return segTree[i][val];
  int mid=l+(r-l)/2;
  return solve(2*i+1,l,mid,start,end,val)+solve(2*i+2,mid+1,r,start,end,val);
}
    RangeFreqQuery(vector<int>& arr) {
       n=arr.size();
       segTree.resize(4*n);
       buildSegTree(0,0,n-1,arr);
    }
    
    int query(int left, int right, int value) {
        return solve(0,0,n-1,left,right,value);
    }
};