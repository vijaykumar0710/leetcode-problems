class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n=stations.size();
        sort(stations.begin(),stations.end());
        priority_queue<int>pq;
        int j=0,cnt=0,dist=startFuel;
        while(target-dist>0){
           while(j<n && stations[j][0]<=dist){
            pq.push(stations[j][1]);
            j++;
           }
           if(pq.empty()) return -1;
           cnt++;
           dist+=pq.top();
           pq.pop();
        }
        return cnt;
    }
};