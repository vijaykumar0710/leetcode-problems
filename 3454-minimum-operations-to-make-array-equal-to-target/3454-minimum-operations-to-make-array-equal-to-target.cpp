class Solution {
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        int n=nums.size();
        vector<int>diff;
        for(int i=0;i<n;i++) diff.push_back(target[i]-nums[i]);
        long long op=0;
        int prev=0;
        for(int i=0;i<n;i++){
           if((prev<0 && diff[i]>0) || (prev>0 && diff[i]<0)) op+=abs(diff[i]);
           else if(abs(prev)<abs(diff[i])){
            op+=abs(diff[i]-prev);
           }
           prev=diff[i];
        }
        return op;
    }
};