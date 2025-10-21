class Solution {
public:
    long long kSum(vector<int>& nums, int k) {
        int n=nums.size();
        long long sum=0;
        for(int i=0;i<n;i++){
            if(nums[i]>0) sum=(long long)sum+nums[i];
            nums[i]=abs(nums[i]);
        }
        sort(nums.begin(),nums.end());
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
        pq.push({nums[0],0});
        vector<long long>temp;
        temp.push_back((long long)0);
        while(temp.size()<k){
            long long val=pq.top().first;
            int idx=pq.top().second;
            pq.pop();
            temp.push_back(val);
            if(idx<n-1){
                pq.push({(long long)val+nums[idx+1],idx+1});
                pq.push({(long long)val+nums[idx+1]-nums[idx],idx+1});
            }
        }
        return sum-temp[k-1];
    }
};