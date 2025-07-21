class Solution {
public:
    int countBinarySubstrings(string s) {
        int n=s.size();
        vector<int>vec;
        int cnt=1;
        for(int i=1;i<n;i++){
            if(s[i]==s[i-1]) cnt++;
            else{
                vec.push_back(cnt);
                cnt=1;
            }
        }
        vec.push_back(cnt);
     int res=0;
     int size=vec.size();
     for(int i=1;i<size;i++){
        res+=min(vec[i],vec[i-1]);
     }
     return res;
    }
};