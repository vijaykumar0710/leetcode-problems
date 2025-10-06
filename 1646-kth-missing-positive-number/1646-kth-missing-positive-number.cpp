class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        unordered_set<int>st;
        for(auto x:arr) st.insert(x);
        for(int i=1;i<=1000;i++){
            if(!st.count(i)) k--;
            if(k==0) return i;
        }
        return -1;
    }
};