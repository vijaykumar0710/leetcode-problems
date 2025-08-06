class NumArray {
public:
int n;
vector<int>segTree;

 void buildSegTree(int i,int l,int r,vector<int>&nums){
    if(l==r){
        segTree[i]=nums[l];
        return;
    }
    int mid=l+(r-l)/2;
    buildSegTree(2*i+1,l,mid,nums);
    buildSegTree(2*i+2,mid+1,r,nums);
    segTree[i]=segTree[2*i+1]+segTree[2*i+2];
 }

void update_query(int i,int l,int r,int idx,int val){
if(l==r){
    segTree[i]=val;
    return;
}
int mid=l+(r-l)/2;
if(idx<=mid) update_query(2*i+1,l,mid,idx,val);
else update_query(2*i+2,mid+1,r,idx,val);
segTree[i]=segTree[2*i+1]+segTree[2*i+2];
}

int range_sum(int i,int l,int r,int start,int end){
    if(start>r || end<l) return 0;
    if(l>=start && r<=end) return segTree[i];
    int mid=l+(r-l)/2;
    return range_sum(2*i+1,l,mid,start,end)+range_sum(2*i+2,mid+1,r,start,end);
}

    NumArray(vector<int>& nums) {
        n=nums.size();
        segTree.resize(4*n);
        buildSegTree(0,0,n-1,nums);
    }
    
    void update(int index, int val) {
        update_query(0,0,n-1,index,val);
    }
    
    int sumRange(int left, int right) {
        return range_sum(0,0,n-1,left,right);
    }
};