class Solution {
public:
vector<int>segTree;
void buildSegTree(int i,int l,int r,vector<int>&baskets){
  if(l==r){
    segTree[i]=baskets[l];
    return;
  }
  int mid=l+(r-l)/2;
  buildSegTree(2*i+1,l,mid,baskets);
  buildSegTree(2*i+2,mid+1,r,baskets);
  segTree[i]=max(segTree[2*i+1],segTree[2*i+2]);
}

int query(int i,int l,int r,int fruit){
  if(segTree[i]<fruit) return -1;
  if(l==r) return l;
  int mid=l+(r-l)/2;
  if(segTree[2*i+1]>=fruit) return query(2*i+1,l,mid,fruit);
  return query(2*i+2,mid+1,r,fruit);
}

void update(int i,int l,int r,int idx,int val){
    if(l==r){
        segTree[i]=val;
        return;
    }
    int mid=l+(r-l)/2;
    if(idx<=mid) update(2*i+1,l,mid,idx,val);
    else update(2*i+2,mid+1,r,idx,val);
    segTree[i]=max(segTree[2*i+1],segTree[2*i+2]);
}

    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n=fruits.size();
        int placed=0;
        segTree.resize(4*n);
        buildSegTree(0,0,n-1,baskets);
       for(auto &fruit:fruits){
         int left_most=query(0,0,n-1,fruit);
         if(left_most!=-1){
            update(0,0,n-1,left_most,0);
            placed++;
         }
       }
       return n-placed;
    }
};