class Solution {
public:
bool isValid(string &a,string &b){
    if(a.size()!=b.size()) return false;
    int differ=0;
    int i=0,j=0;
    while(i<a.size() && j<b.size()){
        if(a[i]!=b[j]) differ++;
        if(differ>1) return false;
        i++,j++;
    }
    return true;
}
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n=words.size();
        vector<int>t(n,1),parent(n,-1);
        int lis_idx=0,max_len=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(groups[i]!=groups[j] && isValid(words[i],words[j])){
                    if(t[i]<t[j]+1){
                        t[i]=t[j]+1;
                        parent[i]=j;
                        if(t[i]>max_len){
                            max_len=t[i];
                            lis_idx=i;
                        }
                    }
                }
            }
        }
        vector<string>res;
        while(lis_idx!=-1){
            res.push_back(words[lis_idx]);
            lis_idx=parent[lis_idx];
        }
        reverse(res.begin(),res.end());
        return res;
    }
};