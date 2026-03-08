class Solution {
public:
    int minOperations(string s) {
        int n=s.size();
        string st=s;
        sort(st.begin(),st.end());
        if(st==s) return 0;
        if(n==2) return -1;
        int l=0,r=n-1;
        while(l<n && s[l]==st[l]) l++;
        while(r>=0 && s[r]==st[r]) r--;
        if(r-l+1<n) return 1;
        string t1=s,t2=s;
        sort(t1.begin(),t1.end()-1);
        sort(t1.begin()+1,t1.end());
        if(t1==st) return 2;
        sort(t2.begin()+1,t2.end());
        sort(t2.begin(),t2.end()-1);
        if(t2==st) return 2;
        return 3;
    }
};