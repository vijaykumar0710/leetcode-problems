class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        int n=flowers.size();
        vector<int>start,end;
        for(auto &vec:flowers){
            int x=vec[0],y=vec[1];
            start.push_back(x);
            end.push_back(y);
        }
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());
        vector<int>res;
        for(auto p:people){
            auto it1=upper_bound(start.begin(),start.end(),p);
            auto it2=lower_bound(end.begin(),end.end(),p);
            int x=it1-start.begin();
            int y=it2-end.begin();
            res.push_back(x-y);
        }
        return res;
    }
};