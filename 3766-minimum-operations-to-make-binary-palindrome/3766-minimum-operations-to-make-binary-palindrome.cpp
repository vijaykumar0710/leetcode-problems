class Solution {
public:
    bool isPalin(string &s){
        int i=0,j=s.size()-1;
        while(i<=j){
            if(s[i]!=s[j]) return false;
            i++,j--;
        }
        return true;
    }
    vector<int> minOperations(vector<int>& nums) {
        int n=nums.size();
        vector<int>palin;
        for(int i=1;i<=5000;i++){ 
        string s=bitset<64>(i).to_string();
        int k=0;
        while(k<s.size()){
            if(s[k]=='1') break;
            k++;
        }
        s=s.substr(k);
        if(isPalin(s)) palin.push_back(i);
        }
        vector<int>res;
        for(int i=0;i<n;i++){
            int x=INT_MAX;
            for(int j=0;j<palin.size();j++){
                x=min(x,abs(nums[i]-palin[j]));
                if(x==0) break;
            }
            res.push_back(x);
        }
        return res;
    }
};