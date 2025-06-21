class Solution {
public:
vector<int>make_freq(string &word,int n){
    vector<int>temp_freq(26,0);
    for(auto &ch:word) temp_freq[ch-'a']++;
    vector<int>final_freq;
    for(auto &fr:temp_freq){
        if(fr>0) final_freq.push_back(fr);
    }
    sort(final_freq.begin(),final_freq.end());
    return final_freq;
}
  int solve(vector<int>&freq,int k){
    int n=freq.size();
    int i=0,ans=INT_MAX;
    for(int i=0;i<n;i++){
        int deletion=0;
        for(int j=0;j<n;j++){
            if(freq[i]>freq[j]) deletion+=freq[j];
            else if(freq[i]+k<freq[j]) deletion+=(freq[j]-freq[i]-k);
        }
        ans=min(ans,deletion);
    }
    return ans;
  }
    int minimumDeletions(string word, int k) {
        int n=word.size();
        vector<int>freq=make_freq(word,n);
        return solve(freq,k);
    }
};