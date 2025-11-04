class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        priority_queue<int,vector<int>,greater<int>>pq(nums.begin(),nums.end());
        vector<int>res(n);
        for(int i=0;i<n;i+=2){
            res[i]=pq.top();
            pq.pop();
        }
        for(int i=1;i<n;i+=2){
            res[i]=pq.top();
            pq.pop();
        }
        return res;
    }
};