class NumArray {
public:
vector<int>BIT,vec;
int n;
void updateBIT(int i,int val){
    for(;i<=n;i+=(i&-i)) BIT[i]+=val;
}
int query(int i){
    int sum=0;
    for(;i>0;i-=(i&-i)){
        sum+=BIT[i];
    }
    return sum;
}
    NumArray(vector<int>& nums) {
        n=nums.size();
        BIT.assign(n+1,0);
        vec.resize(n+1,0);
        for(int i=1;i<=n;i++) vec[i]=nums[i-1],updateBIT(i,nums[i-1]);
    }
    
    void update(int index, int val) {
        index++;
        updateBIT(index,val-vec[index]);
        vec[index]=val;
    }
    
    int sumRange(int left, int right) {
        left++,right++;
        return query(right)-query(left-1);
    }
};