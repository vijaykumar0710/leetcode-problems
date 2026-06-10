class Solution {
public:
vector<pair<long long,long long>>segTree;
void buildSeg(vector<int>&nums,int i,int l,int r){
if(l==r){
    segTree[i]={nums[l],nums[l]};
    return;
}
int mid=l+(r-l)/2;
buildSeg(nums,2*i+1,l,mid);
buildSeg(nums,2*i+2,mid+1,r);
segTree[i]={max(segTree[2*i+1].first,segTree[2*i+2].first),min(segTree[2*i+1].second,segTree[2*i+2].second)};
}
pair<long long,long long>query(int st,int end,int i,int l,int r){
if(l>end || r<st) return {INT_MIN,INT_MAX};
if(l>=st && r<=end) return segTree[i];
int mid=l+(r-l)/2;
pair<long long,long long>left=query(st,end,2*i+1,l,mid);
pair<long long,long long>right=query(st,end,2*i+2,mid+1,r);
return {max(left.first,right.first),min(left.second,right.second)};
}

long long f(vector<int>&nums,int i,int j){
int n=nums.size();
pair<long long,long long> p=query(i,j,0,0,n-1);
return (long long)p.first-p.second;
}
    long long maxTotalValue(vector<int>& nums, int k) {
        int n=nums.size();
        segTree.assign(4*n,{0,0});
        buildSeg(nums,0,0,n-1);
        priority_queue<vector<long long>>pq;
        set<pair<int,int>>st;
        long long val=f(nums,0,n-1);
        pq.push({val,0,n-1});
        long long res=0;
        while(k--){
            auto vec=pq.top();
            pq.pop();
            res+=vec[0];
            if(vec[1]<vec[2]){
                if(!st.count({vec[1]+1,vec[2]})){
                    val=f(nums,vec[1]+1,vec[2]);
                    pq.push({val,vec[1]+1,vec[2]});
                    st.insert({vec[1]+1,vec[2]});
                }
                if(!st.count({vec[1],vec[2]-1})){
                    val=f(nums,vec[1],vec[2]-1);
                    pq.push({val,vec[1],vec[2]-1});
                    st.insert({vec[1],vec[2]-1});
                }
            }
        }
        return res;
    }
};