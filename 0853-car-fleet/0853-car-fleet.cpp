class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n=speed.size();
        vector<pair<int,int>>pair;
        for(int i=0;i<n;i++) pair.push_back({position[i],speed[i]});
        sort(pair.begin(),pair.end());
        int cnt=0;
        double mini=double(target-pair[n-1].first)/pair[n-1].second;
        if(mini!=0.0) cnt++;
        for(int i=n-2;i>=0;i--){
            if((double(target-pair[i].first))/pair[i].second>mini){
                cnt++;
            mini=double(target-pair[i].first)/pair[i].second;
            }
        }
        return cnt;
      }
    };