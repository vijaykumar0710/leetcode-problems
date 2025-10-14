class Solution {
public:
bool isValid(string &word1,string &word2,int i,int j){
    int n1=word1.size(),n2=word2.size();
    while(i<n1 && j<n2){
        if(word1[i]>word2[j]) return true;
        if(word1[i]<word2[j]) return false;
        i++; j++;
    }
    return i!=n1;
}
    string largestMerge(string word1, string word2) {
        int n1=word1.size(),n2=word2.size();
        string res;
        int i=0,j=0;
        while(i<n1 || j<n2){
        if(isValid(word1,word2,i,j)){ res+=word1[i];i++; }
          else{ res+=word2[j];j++; }
        }
        while(i<n1) res+=word1[i],i++;
        while(j<n2) res+=word2[j],j++;
        return res;
    }
};