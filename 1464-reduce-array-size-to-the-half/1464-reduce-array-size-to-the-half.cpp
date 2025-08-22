class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,int>mp;
        priority_queue<int>pq;
        for(auto &num:arr) mp[num]++;
        int cnt=0;
        int freq=0;
        while(!mp.empty()){
            pq.push(mp.begin()->second);
            mp.erase(mp.begin()->first);
        }
        while(freq<n/2){
            freq+=pq.top();
            cnt++;
            pq.pop();
        }
        return cnt;
    }
};