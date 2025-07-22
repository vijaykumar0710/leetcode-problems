class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>>vec,res;
        for(int i=0;i<firstList.size();i++){
            vec.push_back(firstList[i]);
        }
        for(int i=0;i<secondList.size();i++){
            vec.push_back(secondList[i]);
        }
        sort(vec.begin(),vec.end());
        int N=vec.size();
        int prev_st=vec[0][0],prev_end=vec[0][1];
        for(int i=1;i<N;i++){
          if(prev_end>=vec[i][0]){
            int st=max(vec[i][0],prev_st);
            int end=min(vec[i][1],prev_end);
            res.push_back({st,end});
          }
          prev_end=max(prev_end,vec[i][1]);
        }
        return res;
    }
};