class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int>freq(26,0);
        for(auto &ch:s) freq[ch-'a']++;
        char mid='0';
        for(int i=0;i<26;i++){
            if(freq[i]%2==1) mid=i+'a';
            freq[i]/=2;
        }
        string res="";
        string half="";
        for(int i=0;i<26;i++){
            int times=freq[i];
            while(times--) half+=(i+'a');
        }
        string right=half;
        reverse(right.begin(),right.end());
        if(mid=='0') return half+right;
        return half+mid+right;
    }
};