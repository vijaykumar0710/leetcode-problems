class Solution {
public:
    string minWindow(string s, string t) {
        int m=s.size(),n=t.size();
        vector<int>freq(128,0);
        int req=0;
        for(auto ch:t) freq[ch]++,req++;
        int idx=-1,min_len=INT_MAX;
        int i=0;
        for(int j=0;j<m;j++){
            if(freq[s[j]]>0) req--;
            freq[s[j]]--;
            while(req==0){
                if(j-i+1<min_len){
                    idx=i;
                    min_len=j-i+1;
                }
                freq[s[i]]++;
                if(freq[s[i]]>0) req++;
                i++;
            }
        }
        return idx==-1?"":s.substr(idx,min_len);
    }
};