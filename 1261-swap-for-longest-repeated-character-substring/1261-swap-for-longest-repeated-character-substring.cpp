class Solution {
public:
    int maxRepOpt1(string text) {
        int n=text.size();
        int len=0;
        char ch;
        vector<vector<int>>pos(26);
        for(int i=0;i<n;i++) pos[text[i]-'a'].push_back(i);
        for(int i=0;i<26;i++){
            auto &vec=pos[i];
            int l=0;
            for(int r=0;r<vec.size();r++){
                while((vec[r]-vec[l]+1)-(r-l+1)>1) l++;
                if(len<r-l+1){ 
                    ch=text[vec[r]];
                len=max(len,r-l+1);
                }
            }
        }
        if(pos[ch-'a'].size()>len) len++;
        return len;
    }
};