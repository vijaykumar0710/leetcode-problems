class Solution {
public:
    char processStr(string s, long long k) {
        int n=s.size();
        k++;
        vector<long long>len(n,0);
        long long cur_len=0;
        for(int i=0;i<n;i++){
            if(s[i]=='*') cur_len=max(0LL,cur_len-1);
            else if(s[i]=='#') cur_len*=2;
            else if(s[i]=='%') cur_len=cur_len;
            else cur_len++;
            len[i]=cur_len;
        }
        if(k>len[n-1]) return '.';
        for(int i=n-1;i>=0;i--){
            if(s[i]=='*'){
                k=k;
            }else if(s[i]=='#'){
                long long prev_len=(i>0)?len[i-1]:0;
                if(prev_len<k) k=k-prev_len;
            }else if(s[i]=='%'){
                k=len[i]-k+1;
            }else{
                if(k==len[i]) return s[i]; 
            }
        }
        return '.';
    }
};