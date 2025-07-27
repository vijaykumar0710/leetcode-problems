class Solution {
public:
typedef pair<int,char>p;
    string reorganizeString(string s) {
        int n=s.size();
        unordered_map<char,int>mp;
        for(auto &ch:s) mp[ch]++;

        priority_queue<p>pq;
        for(auto &[ch,fre]:mp) pq.push({fre,ch});

        if(pq.top().first>(n+1)/2) return "";

        string res="";
        while(pq.size()>1){
            auto [freq1,ch1]=pq.top();
            pq.pop();
            res+=ch1;

            auto [freq2,ch2]=pq.top();
            pq.pop();
            res+=ch2;

            freq1--;
            freq2--;

            if(freq1!=0) pq.push({freq1,ch1});
            if(freq2!=0) pq.push({freq2,ch2});
        }
        if(!pq.empty()){
            res+=pq.top().second;
        }
        return res;
    }
};