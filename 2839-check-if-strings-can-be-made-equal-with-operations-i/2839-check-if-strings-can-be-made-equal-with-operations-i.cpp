class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        int n=s1.size();
        string st1=s1,st2=s2;
        sort(st1.begin(),st1.end());
        sort(st2.begin(),st2.end());
        if(st1!=st2) return false;
        unordered_map<char,int>st;
        for(int i=0;i<n;i+=2) st[s1[i]]++;
        for(int i=0;i<n;i+=2){
            if(!st.count(s2[i])) return false;
            else {
                st[s2[i]]--;
                if(st[s2[i]]==0) st.erase(s2[i]);
            }
        }
        return true;
    }
};