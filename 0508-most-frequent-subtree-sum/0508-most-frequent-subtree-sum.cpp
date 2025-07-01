class Solution {
public:
 long long solve(TreeNode* root,unordered_map<long long,int>&mp,int &max_freq){
    if(!root) return 0ll;
    long long curr_sum=root->val;
    long long left_sum=solve(root->left,mp,max_freq);
    long long right_sum=solve(root->right,mp,max_freq);
    long long sum=curr_sum+left_sum+right_sum;
    mp[sum]++;
    max_freq=max(max_freq,mp[sum]);
    return sum;
}
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<long long,int>mp;
        int max_freq=-1;
        solve(root,mp,max_freq);
       vector<int>res;
       for(auto &p:mp){
        if(p.second==max_freq)
           res.push_back(p.first);
       }
       return res;
    }
};