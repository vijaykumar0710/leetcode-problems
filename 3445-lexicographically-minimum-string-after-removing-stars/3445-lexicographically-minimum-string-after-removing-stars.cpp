class Solution {
public:
    string clearStars(string s) {
        int n=s.size();
         priority_queue<pair<char, int>, vector<pair<char, int>>, greater<pair<char,int>>> minPq;
        for(int i=0;i<n;i++){
            if(s[i]=='*' && !minPq.empty()){
                minPq.pop();
            }else{
              minPq.push({s[i],-i});
            }
        }
        vector<pair<char,int>>pos;
        while(!minPq.empty()){
            pos.push_back(minPq.top());
            minPq.pop();
        }
       sort(pos.begin(),pos.end(),[](auto &A,auto &B){
        return A.second>B.second;
       });
       string res="";
       for(auto &V:pos){
        res+=V.first;
       }
        return res;
    }
};