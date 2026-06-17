class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n=words.size();
        vector<vector<int>>freq(n,vector<int>(26,0));
        for(int i=0;i<n;i++){
            for(auto ch:words[i]){
                freq[i][ch-'a']=1;
            }
        }
        int maxi=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                bool flag=true;
                for(int it=0;it<26;it++){
                    if(freq[i][it]==1 && freq[j][it]==1){
                        flag=false;
                        break;
                    }
                }
               if(flag) maxi=max(maxi,(int)words[i].size()*(int)words[j].size());
            }
        }
        return maxi;
    }
};