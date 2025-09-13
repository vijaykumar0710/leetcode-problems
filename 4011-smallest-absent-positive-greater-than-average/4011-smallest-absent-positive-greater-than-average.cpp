class Solution {
public:
    int smallestAbsent(vector<int>& nums) {
        int n=nums.size();
        //sort(nums.begin(),nums.end());
        unordered_set<int>st;
        st.insert(nums.begin(),nums.end());
        int total=accumulate(nums.begin(),nums.end(),0);
        double avg=(double)total/n;
        for(int i=1;i<=1000000;i++){
            if(i<=avg) continue;
            if(!st.count(i) && i>avg) return i;
        }
        return 1;
    }
};