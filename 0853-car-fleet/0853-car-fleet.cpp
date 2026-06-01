class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n=speed.size();
        vector<pair<int,int>>pair;
        for(int i=0;i<n;i++) pair.push_back({position[i],speed[i]});
        sort(pair.begin(),pair.end());
        int cnt=0;
        double mini=0.0;
        for(int i=n-1;i>=0;i--){
            if((double(target-pair[i].first))/pair[i].second>mini){
                cnt++;
            mini=double(target-pair[i].first)/pair[i].second;
            }
        }
        return cnt;
      }
    };