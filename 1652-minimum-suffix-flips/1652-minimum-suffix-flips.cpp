class Solution {
public:
    int minFlips(string target) {
        int idx=-1;
        for(int i=0;i<target.size();i++){
            if(target[i]=='1'){
                idx=i;
                break;
            }
        }
        if(idx==-1) return 0;
        vector<int>g;
        int i;
        for(i=idx+1;i<target.size();i++){
            if(target[i]==target[i-1]) continue;
            else g.push_back(target[i-1]);
        }
        g.push_back(target[i-1]);
        return g.size();
    }
};