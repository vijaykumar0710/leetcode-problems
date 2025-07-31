class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        int n=arr.size();
        vector<unordered_set<int>>vec(n);
        unordered_set<int>st;
        vec[0].insert(arr[0]);
        for(int i=1;i<n;i++){
            int num=arr[i];
            for(auto &x:vec[i-1]){
                vec[i].insert(x|num);
            }
            vec[i].insert(num);
        }
        for(auto &v:vec){
            st.insert(v.begin(),v.end());
        }
        return st.size();
    }
};