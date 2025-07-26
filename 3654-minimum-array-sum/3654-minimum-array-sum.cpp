class Solution {
public:
int t[101][101][101];
int f(vector<int>& nums, int k, int op1, int op2,int i,int n){
    if(i==n) return 0;
    if(t[i][op1][op2]!=-1) return t[i][op1][op2];
    int res=INT_MAX;
    if(op1>0){
        int newVal=(nums[i]+1)/2;
        int opr1=newVal+f(nums,k,op1-1,op2,i+1,n);
        res=min(res,opr1);
    }
    if(op2>0 && nums[i]>=k){
        int newVal=nums[i]-k;
        int opr2=newVal+f(nums,k,op1,op2-1,i+1,n);
        res=min(res,opr2);
    }
    if(op1>0 && op2>0){
        int newVal=(nums[i]+1)/2;;
        if(newVal>=k){
            newVal=newVal-k;
             int opr3=newVal+f(nums,k,op1-1,op2-1,i+1,n);
              res=min(res,opr3);
        }
        if(nums[i]>=k){
            newVal=nums[i]-k;
            newVal=(newVal+1)/2;
            int opr4=newVal+f(nums,k,op1-1,op2-1,i+1,n);
            res=min(res,opr4);
        }
    }
        res=min(res,nums[i]+f(nums,k,op1,op2,i+1,n));
    return t[i][op1][op2]=res;
}
    int minArraySum(vector<int>& nums, int k, int op1, int op2) {
        int n=nums.size();
        memset(t,-1,sizeof(t));
        return f(nums,k,op1,op2,0,n);
    }
};