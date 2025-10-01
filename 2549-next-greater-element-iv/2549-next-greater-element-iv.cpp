class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {
        int n=nums.size();
        stack<int>fge;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>sge;
        vector<int>ans(n,-1);
        for(int i=0;i<n;i++){
            int num=nums[i];
            while(!sge.empty() && sge.top().first<num){ans[sge.top().second]=num;sge.pop();} 
            while(!fge.empty() && nums[fge.top()]<num){sge.push({nums[fge.top()],fge.top()});fge.pop();}
            fge.push(i);
        }
        return ans;
    }
};