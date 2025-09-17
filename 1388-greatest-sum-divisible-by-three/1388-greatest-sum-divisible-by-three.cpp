class Solution {
public:
int n;
unordered_map<string,int>t;
int f(int i,vector<int>& nums,int sum){
    if(i>=n){
        if(sum%3==0) return sum;
        return INT_MIN;
    }
    string key=to_string(i)+"$"+to_string(sum);
    if(t.count(key)) return t[key];
    int skip=f(i+1,nums,sum);
    int take=INT_MIN;
    int new_sum=sum+nums[i];
    if(new_sum%3==0) new_sum=0;
    int next=f(i+1,nums,new_sum);
    if(next!=INT_MIN) take=nums[i]+next;
    return t[key]=max(skip,take);
}
    int maxSumDivThree(vector<int>& nums) {
      n=nums.size();
      return f(0,nums,0);  
    }
};