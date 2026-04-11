class NumArray {
public:
vector<int>vec,block;
int n,blocksize;
    NumArray(vector<int>& nums) {
        n=nums.size();
        vec=nums;
        blocksize=ceil(sqrt(n));
        block.resize(blocksize);
        for(int i=0;i<n;i++){
            block[i/blocksize]+=nums[i];
        }
    }
    
    void update(int index, int val) {
        int block_idx=index/blocksize;
        block[block_idx]=(block[block_idx]-vec[index]+val);
        vec[index]=val;
    }
    
    int sumRange(int l, int r) {
        int sum=0;
        int startblock=l/blocksize;
        int endblock=r/blocksize;
        if(startblock==endblock){
            for(int i=l;i<=r;i++) sum+=vec[i];
        }else{
            int endidx=((startblock+1)*blocksize)-1;
            for(int i=l;i<=endidx;i++) sum+=vec[i];
            for(int i=startblock+1;i<=endblock-1;i++) sum+=block[i];
            int startidx=endblock*blocksize;
            for(int i=startidx;i<=r;i++) sum+=vec[i];
        }
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */