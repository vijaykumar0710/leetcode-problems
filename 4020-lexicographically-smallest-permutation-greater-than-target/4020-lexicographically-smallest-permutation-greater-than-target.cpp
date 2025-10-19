class Solution {
public:
int n;
string res="";
bool isFound=false;
void f(int pos,vector<int>&freq,string &s,string &target,string &curr,bool isgreater){
    if(isFound) return;
   if(curr.size()==n){
     if(isgreater){
        res=curr;
        isFound=true;
     }
     return;
   }

    for(auto ch='a';ch<='z';ch++){
        if(freq[ch-'a']==0) continue;
        if(!isgreater && ch<target[pos]) continue;
        curr.push_back(ch);
        freq[ch-'a']--;
        if(ch>target[pos]) isgreater=true;
        f(pos+1,freq,s,target,curr,isgreater);
        curr.pop_back();
        freq[ch-'a']++;
        if(isFound) return;
    }
}
    string lexGreaterPermutation(string s, string target) {
        n=s.size();
        sort(s.begin(),s.end());
        if(s>target) return s;
        vector<int>freq(26,0);
        for(auto ch:s) freq[ch-'a']++;
        string curr="";
        f(0,freq,s,target,curr,false);
        return res;
    }
};