class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int n=passingFees.size();
        unordered_map<int,vector<pair<int,int>>> mp;
        for(auto &it:edges){
            mp[it[0]].push_back({it[1],it[2]});
            mp[it[1]].push_back({it[0],it[2]});
        }
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,
                    greater<pair<int,pair<int,int>>>> pq;
        vector<int> time(n,INT_MAX);
        pq.push({passingFees[0],{0,0}});
        time[0]=0;
        int res=INT_MAX;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int price=it.first;
            int t=it.second.first;
            int node=it.second.second;
            
            if(t>maxTime) continue;
            if(node==n-1) res=min(price,res);
            
            for(auto &i:mp[node]){
                int u=i.first;
                int duration=i.second;
                if(time[u]>duration+t){
                    time[u]=duration+t;
                    pq.push({price+passingFees[u],{t+duration,u}});
                }
            }
        }
        return res==INT_MAX?-1:res;
    }
};