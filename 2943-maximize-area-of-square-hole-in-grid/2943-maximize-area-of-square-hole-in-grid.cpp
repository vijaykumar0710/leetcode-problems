class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());
        int h=0,v=0,cnt=1;
        for(int i=1;i<hBars.size();i++){
            if(hBars[i-1]+1==hBars[i]) cnt++;
            else{ h=max(h,cnt); cnt=1;} 
        }
        h=max(h,cnt);
        cnt=1;
        for(int i=1;i<vBars.size();i++){
            if(vBars[i-1]+1==vBars[i]) cnt++;
            else{ v=max(v,cnt); cnt=1;} 
        }
        v=max(v,cnt);
        int s=min(h,v);
        return (s+1)*(s+1);
    }
};