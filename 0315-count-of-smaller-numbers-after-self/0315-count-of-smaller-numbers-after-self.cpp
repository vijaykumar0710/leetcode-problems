class Solution {
public:
vector<int>res;
map<int,int>BIT;
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
        m=2*maxi+1;
        for(int i=n-1;i>=0;i--){
            int x=query(nums[i]+maxi);
            res[i]=x;
            update(nums[i]+maxi+1);
        }
        return res;
    }
};