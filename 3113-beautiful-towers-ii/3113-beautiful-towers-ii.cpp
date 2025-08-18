class Solution {
public:
typedef long long ll;
    long long maximumSumOfHeights(vector<int>& h) {
        int n=h.size();
        vector<ll>left(n),right(n);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && h[st.top()]>h[i]) st.pop();
            if(st.empty()) left[i]=(ll)h[i]*(i+1);
            else{
                int idx=st.top();
                left[i]=left[idx]+(ll)h[i]*(i-idx);
            }
            st.push(i);
        } 
        st=stack<int>();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && h[st.top()]>h[i]) st.pop();
            if(st.empty()) right[i]=(ll)h[i]*(n-i);
            else{
                int idx=st.top();
                right[i]=right[idx]+(ll)h[i]*(idx-i);
            }
            st.push(i);
        } 
        ll res=0;
       for(int i=0;i<n;i++){
        res=max(res,left[i]+right[i]-h[i]);
       }
       return res;
    }
};