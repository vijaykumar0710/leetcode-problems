class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int len=0;
        vector<vector<int>>pos(26);
        for(int i=0;i<n;i++) pos[s[i]-'A'].push_back(i);
        for(int i=0;i<pos.size();i++){
            auto &vec=pos[i];
            int l=0;
            for(int r=0;r<vec.size();r++){
                while((vec[r]-vec[l]+1)-(r-l+1)>k) l++;
                len=max(len,r-l+1);
            }
        }
        return min(n,len+k);
    }
};