class Solution {
public:
    int numDifferentIntegers(string word) {
        unordered_set<int>st;
        int n=word.size(),i=0;
        while(i<n){
            long long num=0;
            bool flag=false;
            char ch=word[i];
            while(i<n && !isalpha(ch)){
                flag=true;
                num=1ll*num*10+(ch-'0');
                if(num>100000000000) num=0;
                i++;
                ch=word[i];
            }
           if(flag) st.insert(num);
            i++;
        }
        return st.size();
    }
};