class Solution {
public:
void rebalance(multiset<int>&mst1,multiset<int>&mst2){
    if(mst1.size()<mst2.size()){
        mst1.insert(*mst2.begin());
        mst2.erase(mst2.find(*mst2.begin()));
    }
    if(mst1.size()-mst2.size()>1){
        mst2.insert(*mst1.rbegin());
        mst1.erase(mst1.find(*mst1.rbegin()));
    }
}
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int>mst1,mst2;
        vector<double>res;
        int n=nums.size();
        for(int i=0;i<k;i++){
            if(mst1.empty() || nums[i]<*mst1.rbegin()) mst1.insert(nums[i]);
            else mst2.insert(nums[i]);
            rebalance(mst1,mst2);
        }

        if(k%2!=0) res.push_back(*mst1.rbegin());
            else{
                double x=((double)*mst1.rbegin()+*mst2.begin())/2.0;
                res.push_back(x);
            } 

        for(int i=k;i<n;i++){
            if(mst1.count(nums[i-k])!=0) mst1.erase(mst1.find(nums[i-k]));
            else mst2.erase(mst2.find(nums[i-k]));

            if(mst1.empty() || nums[i]<*mst1.rbegin()) mst1.insert(nums[i]);
            else mst2.insert(nums[i]);

            rebalance(mst1,mst2);

            if(k%2!=0) res.push_back(*mst1.rbegin());
            else{
                double x=((double)*mst1.rbegin()+*mst2.begin())/2.0;
                res.push_back(x);
            } 
        }
        return res;
    }
};