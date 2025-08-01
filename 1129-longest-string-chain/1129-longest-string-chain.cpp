class Solution {
public:
 bool isValid(string &a,string &b){
      if(b.size()-a.size()!=1) return false;
            int differ=0;
            int i=0,j=0;
            while(i<a.size()){
                if(a[i]!=b[j]){
                    differ++;
                    j++;
                }else{
                    i++,j++;
                }
                if(differ>1) return false;
            }
            return i>=a.size();
        }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),[](auto &a,auto &b){
           return a.size()<b.size();
        });
        int n=words.size();
        vector<int>t(n,1);
        int max_len=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(isValid(words[j],words[i])){
                    if(t[i]<t[j]+1){
                        t[i]=t[j]+1;
                        max_len=max(max_len,t[i]);
                    }
                }
            }
        }
        return max_len;
    }
};