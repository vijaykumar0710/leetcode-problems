class Solution {
public:
const int M=1e9+7;
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        vFences.push_back(1);
        vFences.push_back(n);
        hFences.push_back(1);
        hFences.push_back(m);
        sort(vFences.begin(),vFences.end());
        sort(hFences.begin(),hFences.end());
        set<int>st;
        long long side=-1;
        for(int i=0;i<vFences.size();i++){
            for(int j=i+1;j<vFences.size();j++){
                st.insert(vFences[j]-vFences[i]);
            }
        }
        for(int i=0;i<hFences.size();i++){
            for(int j=i+1;j<hFences.size();j++){
                long long sid=hFences[j]-hFences[i];
                if(st.count(sid)) side=max(side,sid);
            }
        }
        if(side==-1) return -1;
         return (1ll*side*side)%M;
    }
};