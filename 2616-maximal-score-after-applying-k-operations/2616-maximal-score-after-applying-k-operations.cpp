class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<long long>pq;
        for(auto &x:nums) pq.push(x);
        long long pro=0;
        for(int i=0;i<k;i++){
            int val=pq.top();
            pro+=val;
            pq.pop();
            pq.push(ceil((double)val/3));
        } 
        return pro;
    }
};