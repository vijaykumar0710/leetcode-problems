class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        int n=nums.size();
        vector<int>res;
        stack<int>st;
        for(int i=0;i<n;i++){
            int x=nums[i];
           if(!st.empty() && gcd(st.top(),x)>1){
             int l=lcm(x,st.top());st.pop();
              while(!st.empty() && gcd(st.top(),l)>1){ l=lcm(st.top(),l),st.pop(); }
              st.push(l);
           }else st.push(x);
        }
        while(!st.empty()){ res.push_back(st.top()); st.pop(); }
        reverse(res.begin(),res.end());
        return res;
    }
};