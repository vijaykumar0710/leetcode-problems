class Solution {
public:
int x_sum(vector<int>&arr,int x){
  unordered_map<int,int>mp;
  for(auto &num:arr) mp[num]++;
  if(mp.size()<x) return accumulate(arr.begin(),arr.end(),0);
  priority_queue<pair<int,int>>pq;
  for(auto [num,fre]:mp){
    pq.push({fre,num});
  }
  int sum=0;
  while(x--){
   sum+=pq.top().second*pq.top().first;
   pq.pop();
  }
  return sum;
}
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n=nums.size();
        vector<int>res;
        for(int i=0;i<=n-k;i++){
            vector<int>vec(nums.begin()+i,nums.begin()+i+k);
            int val=x_sum(vec,x);
            res.push_back(val);
        }
        return res;
    }
};