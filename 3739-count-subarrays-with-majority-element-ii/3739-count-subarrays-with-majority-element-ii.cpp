class Solution {
public:
unordered_map<int,int>seg;
int query(int qs,int qe,int idx,int l,int r){
    if(qe<l || qs>r) return 0;
    if(qs<=l && r<=qe) return seg[idx];
    int mid=l+(r-l)/2;
    return query(qs,qe,2*idx+1,l,mid)+query(qs,qe,2*idx+2,mid+1,r);
}
void update(int pos,int idx,int l,int r){
if(l==r){
    seg[idx]++;
    return;
  }
 int mid=l+(r-l)/2;
 if(pos<=mid) update(pos,2*idx+1,l,mid);
 else update(pos,2*idx+2,mid+1,r);
 seg[idx]=seg[2*idx+1]+seg[2*idx+2];
}
long long countSmaller(vector<int>&prefix_vec){
    int n=prefix_vec.size();
    long long res=0;
    int l=*min_element(prefix_vec.begin(),prefix_vec.end());
    int r=*max_element(prefix_vec.begin(),prefix_vec.end());
    for(int i=0;i<n;i++){
      res+=query(l,prefix_vec[i]-1,0,l,r);
      update(prefix_vec[i],0,l,r);
    }
    return res;
}
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int>vec;
        for(int i=0;i<n;i++){
            if(nums[i]==target) vec.push_back(1);
            else vec.push_back(-1);
        }
        vector<int>prefix_vec(n+1,0);
        for(int i=1;i<=n;i++) prefix_vec[i]=prefix_vec[i-1]+vec[i-1];
        return countSmaller(prefix_vec);
    }
};