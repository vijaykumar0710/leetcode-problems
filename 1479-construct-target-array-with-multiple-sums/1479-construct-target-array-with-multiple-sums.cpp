class Solution {
public:
    bool isPossible(vector<int>& target) {
        int n=target.size();
        long long sum=accumulate(target.begin(),target.end(),0LL);
        priority_queue<int>pq;
        for(auto x:target) pq.push(x);
        if(pq.top()<n) return false;
        while(pq.top()!=1){
            int max_val=pq.top();
            pq.pop();
            long long rem=sum-max_val;
            if (max_val == 1 || rem == 1) return true; // base case
            if(rem==0 || rem>=max_val) return false;
            long long prev_val=max_val%rem;
            if(prev_val==0) prev_val=rem;
            sum=rem+prev_val;
            pq.push(prev_val);
        }
        return true;
    }
}; 