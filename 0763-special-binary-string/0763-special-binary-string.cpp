class Solution {
public:
string f(string &s){
    int n=s.size();
int cnt=0,start=0;
vector<string>block;
for(int i=0;i<n;i++){
    if(s[i]=='1') cnt++;
    else cnt--;
    if(cnt==0){
        string inner=s.substr(start+1,i-start-1);
        string solved=f(inner);
        string res="1"+solved+"0";
        block.push_back(res);
        start=i+1;
    }
}
sort(block.rbegin(),block.rend());
string ans;
for(auto &x:block) ans+=x;
return ans;
}
    string makeLargestSpecial(string s) {
        return f(s);
    }
};