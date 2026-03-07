class Solution {
public:
vector<int>BIT;
int m;
void update(int i){
for(;i<=m;i+=i&-i) BIT[i]+=1;
}
int query(int i){
int res=0;
for(;i>0;i-=(i&-i)){
    res+=BIT[i]; 
  }
  return res;
}
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        vector<int>res(n);
        vector<int>temp=nums;
        sort(temp.begin(),temp.end());
        temp.erase(unique(temp.begin(),temp.end()),temp.end());
        m=temp.size();
        BIT.assign(m+1,0);
        for(int i=n-1;i>=0;i--){
            int rank=lower_bound(temp.begin(),temp.end(),nums[i])-temp.begin()+1;
            res[i]=query(rank-1);
            update(rank);
        }
        return res;
    }
};