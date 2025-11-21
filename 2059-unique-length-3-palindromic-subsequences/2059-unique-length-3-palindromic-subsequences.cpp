class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n=s.size(),res=0;
        vector<pair<int,int>>ind(26,{1e6,-1});
        for(int i=0;i<n;i++){
            int idx=s[i]-'a';
            ind[idx].first=min(i,ind[idx].first);
            ind[idx].second=max(i,ind[idx].second);
        }
        for(int i=0;i<26;i++){
            int first=ind[i].first;
            int last=ind[i].second;
            if(first==last || first==1e6) continue;
            set<char>st;
            for(int j=first+1;j<last;j++){
                st.insert(s[j]);
            }
            res+=st.size();
        }
        return res;
    }
};