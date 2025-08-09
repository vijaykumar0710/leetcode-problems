class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n=answerKey.size();
        int len=0;
        vector<vector<int>>pos(2);
        for(int i=0;i<n;i++){
            if(answerKey[i]=='T') pos[0].push_back(i);
            else pos[1].push_back(i);
        }
       for(int i=0;i<2;i++){
        auto &vec=pos[i];
        int l=0;
        for(int r=0;r<vec.size();r++){
             while((vec[r]-vec[l]+1)-(r-l+1)>k)l++;
             len=max(len, r-l+1);
         }
       }
       return min(n,len+k);
    }
};