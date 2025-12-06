class Solution {
public:
    int MOD=1e9+7;
    int countPartitions(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>t(n+1,0);
        vector<int>ps(n+2,0);
        t[0]=1;
        ps[1]=1;
        deque<int>maxDeque,minDeque;
        int l=0;
        for(int r=1;r<=n;r++){
            int num=nums[r-1];
        while(!maxDeque.empty() && nums[maxDeque.back()]<num)
            maxDeque.pop_back();
            maxDeque.push_back(r-1);
         while(!minDeque.empty() && nums[minDeque.back()]>num)
            minDeque.pop_back();
            minDeque.push_back(r-1);
        while(!maxDeque.empty() && !minDeque.empty() && nums[maxDeque.front()]-nums[minDeque.front()]>k){
             if(maxDeque.front()==l){
                 maxDeque.pop_front();
             }
            if(minDeque.front()==l){
                minDeque.pop_front();
            }
            l++;
        }
        t[r]=(ps[r]-ps[l]+MOD)%MOD;
        ps[r+1]=(ps[r]+t[r])%MOD;
        }
        return t[n];
    }
};