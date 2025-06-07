class Solution {
public:
//struct Compare {
//     bool operator()( auto& a,  auto& b) {
//         if (a.first == b.first) {
//             // For same character, prioritize the larger index (i.e., reverse the comparison)
//             return a.second < b.second;
//         }
//         // Normal lexicographical order (min-heap by char)
//         return a.first > b.first;
//     }
// };
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
        return A.second<B.second;
       });
       string res="";
       for(auto &V:pos){
        res+=V.first;
       }
       reverse(res.begin(),res.end());
        return res;
    }
};