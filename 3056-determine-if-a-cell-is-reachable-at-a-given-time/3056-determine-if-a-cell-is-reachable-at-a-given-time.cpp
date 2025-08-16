class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int h_d=abs(fy-sy);
        int v_d=abs(fx-sx);
        if(sx==fx && sy==fy && t==1) return false;
        int min_time=max(h_d,v_d);
        return min_time<=t;
    }
};