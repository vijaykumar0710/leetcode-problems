class Solution {
public:
    int countPairs(vector<vector<int>>& cor, int k) {
        int cnt=0;
        int n=cor.size();
        map<pair<int,int>,int>mp;
        for(int i=0;i<n;i++){ //n
            int x1=cor[i][0],y1=cor[i][1];
            for(int x=0;x<=k;x++){//k
                int x2=x^x1,y2=(k-x)^y1;
                if(mp.count({x2,y2})) cnt+=mp[{x2,y2}];
            }
             mp[{x1,y1}]++;
        }
        return cnt;
    }
}; 