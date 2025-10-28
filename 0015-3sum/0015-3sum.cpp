class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        set<vector<int>>st;
        vector<pair<int,int>>pairs;
        for(int i=0;i<n;i++)pairs.push_back({nums[i],i});
        sort(pairs.begin(),pairs.end());
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int target=-1*(pairs[i].first+pairs[j].first);
                int it=lower_bound(pairs.begin()+j+1,pairs.end(),make_pair(target,-1))-pairs.begin();
                if(it>=0 && it<n && pairs[it].first==target){
                    st.insert({pairs[i].first,pairs[j].first,pairs[it].first});
                }
            }
        }
        vector<vector<int>>res;
        for(auto &vec:st) res.push_back(vec);
        return res;
    }
};