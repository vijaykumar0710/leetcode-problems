class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n=strs.size();
        vector<string>vec(strs[0].length(),"");
        for(auto word:strs){ //100
            for(int i=0;i<word.size();i++){ //1000
                vec[i]+=word[i];
            }
        }
        int cnt=0;
        for(auto str:vec){ //100
            string st=str; //1000log1000
            sort(st.begin(),st.end());
            if(str!=st) cnt++;
        }
        return cnt;
    }
};