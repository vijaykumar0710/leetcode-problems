class Solution {
public:
vector<int>res,BIT;
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
        res.resize(n);
        int maxi=10001;
        BIT.assign(2*maxi+5,0);
        m=BIT.size();
        for(int i=n-1;i>=0;i--){
            int x=query(nums[i]+maxi);
            res[i]=x;
            update(nums[i]+maxi+1);
        }
        return res;
    }
};