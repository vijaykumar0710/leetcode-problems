class Solution {
public:
const long long b=31;
unordered_map<unsigned long long,int>mp;
void update(unsigned long long s,int i,vector<string>& wc){
if(!mp.count(s)) mp[s]=i;
else{
    int curr=mp[s];
    if(wc[curr].length()>wc[i].length()) mp[s]=i;
  }
}
    vector<int> stringIndices(vector<string>& wc, vector<string>& wq) {
        int m=wc.size(),n=wq.size();
        for(int i=0;i<m;i++){
            unsigned long long hash=1;
            update(0,i,wc);
            for(int j=wc[i].size()-1;j>=0;j--){
                hash=hash*b+wc[i][j];
                update(hash,i,wc);
            }
        }
         vector<int>res(n);
        for(int i=0;i<n;i++){
            unsigned long long hash=1;
            res[i]=mp[0];
            for(int j=wq[i].size()-1;j>=0;j--){
                hash=hash*b+wq[i][j];
                if(mp.count(hash)) res[i]=mp[hash];
                else break;
            }
        }
        return res;
    }
};