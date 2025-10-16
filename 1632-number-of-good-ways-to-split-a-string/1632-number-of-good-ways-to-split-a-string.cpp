class Solution {
public:
    int numSplits(string s) {
      int n=s.size();
      unordered_set<int>st;
      vector<int>prefix(n),suffix(n);
      for(int i=0;i<n;i++){
         st.insert(s[i]);
         prefix[i]=st.size();
      }
      st.clear();
      for(int i=n-1;i>=0;i--){
        st.insert(s[i]);
        suffix[i]=st.size();
      }
      int res=0;
      for(int i=0;i<n-1;i++){
         if(prefix[i]==suffix[i+1]) res++;
      }
      return res;
    }
};