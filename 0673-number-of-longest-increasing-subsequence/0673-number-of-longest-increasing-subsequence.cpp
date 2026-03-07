class Solution {
public:
int n;
unsigned int maxn=2000005;
unordered_map<unsigned int,unordered_map<unsigned int,unsigned int>>BIT;
void update(unsigned int num,unsigned int len,unsigned int val){
for(;num<=maxn;num+=num&-num) BIT[num][len]+=val;
}
unsigned int query(unsigned int num,unsigned int len){
    unsigned int res=0;
    for(;num>0;num-=num&-num) res+=BIT[num][len];
    return res;
}
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        int LIS=1;
        vector<int>t(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    t[i]=max(t[i],t[j]+1);
                    LIS=max(LIS,t[i]);
                }
            }
        }
        unsigned int offset=1000001;
        for(int i=0;i<n;i++){
            update(nums[i]+offset,1,1);
            for(int j=2;j<=LIS;j++){
                update(nums[i]+offset,j,query(nums[i]+offset-1,j-1));
            }
        }
        return (int)query(maxn,LIS);
    }
};