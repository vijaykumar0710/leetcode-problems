class Solution {
public:
unordered_map<int,vector<int>>mp;
    int longestBalanced(string s) {
        int n=s.size();
        mp.clear();
        mp[-1]=vector<int>(26,0);
        for(int i=0;i<n;i++){
            mp[i]=vector<int>(26,0);
            mp[i]=mp[i-1];
            mp[i][s[i]-'a']++;
        }
     int res=0;
     for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int freq=-1;
            bool flag=true;
            for(int k=0;k<26;k++){
                int diff=mp[j][k]-mp[i-1][k];
                if(diff==0) continue;
                else if(freq==-1) freq=diff;
                else if(freq!=diff){
                    flag=false;
                    break;
                }
            }
           if(flag) res=max(res,(j-i+1));
        }
     }
     return res;
    }
};