class Solution {
public:
    int removeAlmostEqualCharacters(string word) {
        int n=word.size();
        int cnt=0;
        int i=0;
        while(i<n-1){
            if(abs(word[i]-word[i+1])<=1) cnt++,i++;
            i++;
        }
        return cnt;
    }
};