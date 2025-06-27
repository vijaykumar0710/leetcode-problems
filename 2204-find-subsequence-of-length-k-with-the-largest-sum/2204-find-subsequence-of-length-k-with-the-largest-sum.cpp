class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n=nums.size();
        vector<pair<int,int>>p;
        for(int i=0;i<n;i++){
            p.push_back({nums[i],i});
        }
        sort(p.begin(),p.end());
        vector<pair<int,int>>temp;
        for(int i=0;i<k;i++){
            int num=p[n-i-1].first;
            int idx=p[n-i-1].second;
            temp.push_back({idx,num});
        }
        sort(temp.begin(),temp.end());
        vector<int>res;
        for(int i=0;i<k;i++)
        res.push_back(temp[i].second);
        return res;
    }
};